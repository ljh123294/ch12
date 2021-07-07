#include <string>
#include <iostream>
#include <memory>

struct destination
{
    std::string des;
    destination(std::string des_) : des(des_) {}
};

struct connection
{
    std::string conn;
    connection(std::string conn_) : conn(conn_) {}
};

connection connect(destination *des_)
{
    std::cout << "connect to " << des_->des << std::endl;
    return connection(des_->des);
}

void disconnect(connection conn_)
{
    std::cout << "disconnect " << conn_.conn << std::endl;
}

void end_connection(connection *p) { disconnect(*p); }

void f(destination &&d)
{
    connection c = connect(&d);
    // std::shared_ptr<connection> sp(&c, end_connection);
    std::shared_ptr<connection> sp(&c, [](connection *p)
                                   { disconnect(*p); });
    std::cout << "connecting now(" << sp.use_count() << ")" << std::endl;
}

int main()
{
    destination des = destination("dd");
    // destination des("myDes");
    f(destination("dd"));
    int &&a = 1;
    a = 9;
    std::cout << a << std::endl;
    return 0;
}