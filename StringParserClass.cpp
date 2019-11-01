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

StringParserClass::StringParserClass(void)
{
	pStartTag = NULL;
	pEndTag = NULL;
	areTagsSet = false;
}

StringParserClass::~StringParserClass(void)
{
	cleanup();
}

int StringParserClass::setTags(const char *pStart, const char *pEnd)
{
	if (pStart == NULL || pEnd == NULL) return ERROR_TAGS_NULL;
	pDataToSearchThru
	int is = strlen(pStart);
	pStartTag = new char[is+1];
	strncpy(pStartTag, pStart, is);

	int ie = strlen(pEnd);
	pEndTag = new char[ie+1];
	strncpy(pEndTag, pEnd, ie);

	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
		std::vector<std::string> &myVector)
{
	if (pStartTag == NULL || pEndTag == NULL) return ERROR_TAGS_NULL;

	if (pDataToSearchThru == NULL) return ERROR_DATA_NULL;

	myVector.clear();

	char *start = pDataToSearchThru;
	char *end = pDataToSearchThru;

	for (unsigned int i = 0; i < strlen(pDataToSearchThru); i++) end++;

	findTag(pStartTag, start, end);
	findTag(pEndTag, start, end);

	/*std::string s = "";
	start++;

	while (start != end)
	{
		s += *start;
		start++;
	}

	myVector.push_back(s);*/

	return SUCCESS;
}

void StringParserClass::cleanup()
{
	if (pStartTag) delete[] pStartTag;

	if (pEndTag) delete[] pEndTag;
}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd)
{
	if (pStart == NULL || pEnd == NULL)
		return ERROR_TAGS_NULL;

	while (!areTagsSet)
	{
		if (*pStart == '<')
		{
			if (*pEnd == '>')
			{
				//try comparison
			}
			pEnd--;
			continue;
		}
		pStart++;
	}

	return SUCCESS;
}



