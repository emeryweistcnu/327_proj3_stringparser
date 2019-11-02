/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

using namespace KP_StringParserClass;

char *pStartTag;
char *pEndTag;
bool areTagsSet;

StringParserClass::StringParserClass(void) {
	pStartTag = NULL;
	pEndTag = NULL;
	areTagsSet = false;
}

StringParserClass::~StringParserClass(void) {
	cleanup();
}

int StringParserClass::setTags(const char *pStart, const char *pEnd) {
	if (pStart == NULL || pEnd == NULL)
		return ERROR_TAGS_NULL;

	int is = strlen(pStart);
	pStartTag = new char[is + 1];
	strncpy(pStartTag, pStart, is);

	int ie = strlen(pEnd);
	pEndTag = new char[ie + 1];
	strncpy(pEndTag, pEnd, ie);

	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
		std::vector<std::string> &myVector) {
	if (pStartTag == NULL || pEndTag == NULL)
		return ERROR_TAGS_NULL;

	if (pDataToSearchThru == NULL)
		return ERROR_DATA_NULL;

	myVector.clear();

	char *start = pDataToSearchThru;
	char *end = pDataToSearchThru;

	char* pStartCopy = new char[strlen(pStartTag)];
	strncpy(pStartCopy, pStartTag, strlen(pStartTag));
	char* pDataCopy = new char[strlen(pDataToSearchThru)];
	strncpy(pDataCopy, pDataToSearchThru, strlen(pDataToSearchThru));
	while (findTag(pStartCopy, pDataToSearchThru, pDataCopy) == 0) {
		std::string data = "";
		while (*pDataToSearchThru != '<') {
			data += *pDataToSearchThru;
			pDataToSearchThru++;
		}
		myVector.push_back(data);
	}

	return SUCCESS;
}

void StringParserClass::cleanup() {
	if (pStartTag)
		delete[] pStartTag;

	if (pEndTag)
		delete[] pEndTag;
}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart,
		char *&pEnd) {
	if (pStart == NULL || pEnd == NULL)
		return ERROR_TAGS_NULL;

	while (*pStart != '\0') {
		bool startFound = true;

		if (*pStart == '<') {
			char* pCopy = new char[strlen(pTagToLookFor)];
			strncpy(pCopy, pTagToLookFor, strlen(pTagToLookFor));
			while (*pCopy != '>') {
				if (*pCopy != *pStart) {
					startFound = false;
				}
				pStart++;
				pCopy++;
			}

			if (startFound) {
				break;
			}
		} else {
			pStart++;
		}
	}
	if (*pStart != '\0') {
		pStart++;
	}
	while (*pEnd != '\0') {
		bool endFound = true;

		if (*pEnd == '<' && pEnd[1] == '/') {
			char* pCopy = new char[strlen(pTagToLookFor)];
			strncpy(pCopy, pTagToLookFor, strlen(pTagToLookFor));
			pCopy += 1;
			pEnd += 2;
			while (*pCopy != '>') {
				if (*pCopy != *pEnd) {
					endFound = false;
				}
				pEnd++;
				pCopy++;
			}

			if (endFound) {
				break;
			}
		} else {
			pEnd++;
		}
	}

	if (*pStart != '\0' && *pEnd != '\0') {
		return SUCCESS;
	}

	return FAIL;
}

