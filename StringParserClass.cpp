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

}

int StringParserClass::setTags(const char *pStart, const char *pEnd)
{
	if (pStart == NULL || pEnd == NULL)
		return ERROR_TAGS_NULL;

	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
		std::vector<std::string> &myVector)
{
	if (pDataToSearchThru == NULL)
		return ERROR_DATA_NULL;

	myVector.clear();

	return SUCCESS;
}

void StringParserClass::cleanup()
{

}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd)
{
	if (pStart == NULL || pEnd == NULL)
		return ERROR_TAGS_NULL;

	return SUCCESS;
}



