/* Author: David Alter
Description: Implmentation of API request class, makes use of the curl library to retrieve
data in a string format.
Date: Feb 7th, 2023
*/

#include "request.h"
#include <iostream>
#include <curl/curl.h>

// constructor which takes url
Request::Request(std::string url) : i_url(url)
{
}

// destructor
Request::~Request()
{
}

// code taken mostly from getinmemory.c from curl documentation and other online resources
// returns true if the request was successful.
bool Request::Execute()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, i_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &i_result);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK);
    }
    return false;
}

// return the result of the Execute method
std::string Request::Result()
{
    return i_result;
}

// callback method also taken from docs
size_t Request::writeCallback(char *ptr, size_t size, size_t nmemb, std::string *userdata)
{
    userdata->append(ptr, size * nmemb);
    return size * nmemb;
}
