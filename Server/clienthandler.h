#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

class ClientHandler
{
public:
    ClientHandler();
    const char* handleData(const char* data);
    static int player;
};

#endif // CLIENTHANDLER_H
