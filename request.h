/* Author: David Alter
Description: header file for API request, makes use of the curl library to retrieve
data in a string format.
Date: Feb 7th, 2023
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <curl/curl.h>

class Request
{
public:
    Request(std::string url); // taking in url
    ~Request();               // destructor
    bool Execute();           // execute the request
    std::string Result();     // return the result

private:
    std::string i_url;    // store the url
    std::string i_result; // store the result
    static size_t writeCallback(char *ptr, size_t size, size_t nmemb, std::string *userdata);
};

#endif