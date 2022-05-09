# Before You Begin

Familiarize yourself with the functions used in the template provided in problem statement


In Summary:

**Procedure in Client-Server Communication:**
1. **Socket:** Create a new communication
2. **Bind:** Attach a local address to a socket
3. **Listen:** Announce willingness to accept connections
4. **Accept:** Block caller until a connection request arrives
5. **Connect:** Actively attempt to establish a connection
6. **Write:** Write some data into the socket
7. **Read:** Read data from the socket
8. **Close:** Release the connection

Go through the single threaded [server](https://www.cse.iitb.ac.in/~mythili/os/labs/lab-kvserver/simple-server.c) and [client](https://www.cse.iitb.ac.in/~mythili/os/labs/lab-kvserver/simple-client.c) programs and understand its working.


Go through the specific functions and arguments required from blogs [Learning Socket Programming in cpp](https://www.codingninjas.com/blog/2020/07/06/learning-socket-programming-in-c/) and [Socket Programming](https://www.geeksforgeeks.org/socket-programming-cc/) from gfg.


Feel free to go through socket programming basics from [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/). You can also see simple examples of socket programs in the prescribed textbook [Peterson and Davie, Sec 1.4](https://book.systemsapproach.org/foundation/software.html?highlight=socket#application-programming-interface-sockets).


**Important:** For the proper implementation of point 5) above, you must use **mutex lock** available in the pthread library. See the section on [Thread Synchronization](Thread_Synchronization/README.md) for more details.

## Further Readings

1. [Thread Creation](Thread_Creation/README.md)
2. [Thread Synchronization](Thread_Synchronization/README.md)



