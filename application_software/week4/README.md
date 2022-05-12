# Bootcamp Week 4: More features in HTTP server

This week, you will add more features to the simple HTTP server built in the previous week. Some suggested features are as follows.

1. The simple HTTP server built in the previous week could only handle static web pages stored in the file system. Modify the server to handle dynamic HTTP responses as well. That is, you can handle URLs that do not correspond to any file in the HTML root directory, but will instead run some function to generate a dynamic HTTP response. For example, the URL ```/hello``` can return a HTML web page that says Hello to the user. Or, the URL ```/hello?CSERL``` can return a HTML response that says ```Hello CSERL```. You can modify the function that generates HTML responses to handle a wide variety of URLs in this manner.

2. You can support more types of HTTP requests from the HTTP specifications. You can return a more complete set of HTTP headers also in your responses. You can also support persistent connections and other features of HTTP 1.1. This part of the assignment is open-ended, and you can make your HTTP server as close to a real-world server as you wish. 
