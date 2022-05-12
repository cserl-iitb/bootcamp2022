#include "http_server.h"
#include <vector>
#include <sys/stat.h>
#include <sstream>
#include <fstream>


vector<string> split(const string &s, char delim) {
    vector<string> elems;

    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        if(!item.empty())
            elems.push_back(item);
    }

    return elems;
}

HTTP_Request::HTTP_Request(string request)
{
    vector<string> lines = split(request, '\n');
    vector<string> first_line = split(lines[0], ' ');

    this->HTTP_version = "1.0";  //We'll be using 1.0 irrespective of the request

    /*
     TODO : extract the request method, URI and HTTP version from first_line here
    */

    if(this->method != "GET")
    {
        cerr<<"Method '"<<this->method<<"' not supported"<<endl;
        exit(1);
    }
}


HTTP_Response* handle_request(string req)
{
    HTTP_Request *request = new HTTP_Request(req);

    HTTP_Response *response = new HTTP_Response();

    string url = string("html_files/") + request->url;

    response->HTTP_version = "1.0";

    struct stat sb;
    if(stat(url.c_str(), &sb) == 0)  // requested path exists
    {
        response->status_code = 200;
        response->status_text = "OK";

        response->content_type = "text/html";
        string body;

        if(S_ISDIR(sb.st_mode))
        {
            /*
            In this case, requested path is a directory.
            TODO : find the index.html file in that directory (modify the url accordingly)
            */
        }

        /*
        TODO : open the file and read its contents
        */

        /*
        TODO : set the remaining fields of response appropriately
        */
    }

    else
    {
        response->status_code = 404;
        response->status_text = "Not Found";

        /*
        TODO : set the remaining fields of response appropriately
        */
    }

    delete request;

    return response;
}


string HTTP_Response::get_string()
{
    /*
    TODO : implement this function
    You can use sprintf to print to a string
    */
}