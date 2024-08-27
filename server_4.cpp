#define _WINSOCK_DEPRECATED_NO_WARNINGS
//Tắt các cảnh báo về các hàm cũ, lỗi thời trong thư viện WINSOCKET
#define _CRT_SECURE_NO_WARNINGS
#define noi_luu_tep "C:\\server_HDH\\"
#pragma comment(lib, "ws2_32.lib")
//Thư viện cung cấp các hàm để phát triển App mạng trên Windows
#include <iostream>
#include <WinSock2.h>
#include <string>
#include <fstream>
using namespace std;

#define buffer_size 1024;

int main() {

    //cout << "Hello world!" << endl;
    //cout << "Attemting to create a server" << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "                  __________________________________" << endl;
    cout << "                 |  ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "DROPBOX - SERVER: PHAN MAY CHU";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "  | " << endl;
    cout << "                 |__________________________________|" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "                     Noi luu tru: C:\\server_HDH\\" << endl<<endl;
    int cont = 1;

    
        SOCKET wsocket;            //biến lưu socket chính của máy chủ
        SOCKET new_wsocket;        //biến lưu socket mới đc chấp nhận từ khách
        WSADATA wsaData;           //biến lưu thông tin phiên bản Winsock được dùng
        struct sockaddr_in server, client; //biến lưu thông tin đc, cổng máy chủ
        int server_len;            //biến lưu kích thước địa chỉ máy chủ
        int BUFFER_SIZE = 37020;   //biến lưu kích thước buffer dùng nhận dữ liệu từ khách
        char bufferchar[1024];

        //initialize - khởi tạo WinSock phiên bản 2.2
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
            cerr << "Could not initialize - Khong the khoi tao! \n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else cout << "=>Y: Khoi tao WinSock thanh cong" << endl;

        //create a socket - tạo một socket
        wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        /*
        domain = AF_INET - xác định socket IPv4 được tạo (xác định loại giao thức mạng)
        type = SOCK_STREAM - xác định loại Socket(socket có luồng dữ liệu 2 chiều đc tạo, dùng giao thức TCP
        protocol = IPPROTO_TCP - xác định giao thức mạng (TCP)
        */
        if (wsocket == INVALID_SOCKET) { 
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
            cerr << "Could not create socket - Khong the tao Socket! \n" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else cout << "=>Y: Tao socket thanh cong." << endl;

        //    http://localhost:8080/
        //bind socket to address - liên kết socket với địa chỉ
        server.sin_family = AF_INET;    //địa chỉ IP được dùng là IPv4
        server.sin_addr.s_addr = inet_addr("127.0.0.1"); //địa chỉ IP của máy chủ
        //IP: 127.0.0.1 máy chủ lắng nghe trên cùng máy tính này, giao tiếp với chính máy này             
        server.sin_port = htons(8080);   //số hiệu cổng mạng của máy chủ (0-65535)
        server_len = sizeof(server);     //kích thước (bytes) của cấu trúc server

        //gắn kết socket tới server, truyền địa chỉ server dưới dạng con trỏ SOCKADDR*
        if (bind(wsocket, (SOCKADDR*)&server, server_len) != 0) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
            cerr << "ERROR-Could not bind socket - Khong the ket noi Socket!" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }   //kiểm tra kết quả gắn kết socket
        else cout << "=>Y: Ket noi socket thanh cong." << endl;

        //listen to address - nghe địa chỉ
        if (listen(wsocket, SOMAXCONN) != 0) {    //socket chấp nhận tối đa 20 kết nối mỗi đợt
            cerr << "Could not start listening - Khong the bat dau nghe!\n";
        }
        else cout << "  Dang nghe dia chi ..." << endl;

        cout << "=> Listening on 127.0.0.1:8080 \n";

        while (true) {
            cout << "          LAN ";
            SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN ); 
            cout<< cont << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            SOCKET client_socket;
            sockaddr_in client_address;
            int client_address_size = sizeof(client_address);

            client_socket = accept(wsocket, (struct sockaddr*)&client_address, &client_address_size);
            if (client_socket == INVALID_SOCKET) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cerr << "  ERROR-Khong chap nhan ket noi Client: " << WSAGetLastError() << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                closesocket(wsocket);
                WSACleanup();
                return 1;
            }

            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));

            int bytesRead = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
            if (bytesRead == SOCKET_ERROR) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cerr << "  ERROR-Khong nhan duoc ten File " << WSAGetLastError() << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                closesocket(client_socket);

            }
            string ten_tep(buffer);
            cout << "  =>Y: Da nhan ten File: " << ten_tep << std::endl;

            string file_path = noi_luu_tep + ten_tep;
            FILE* file = fopen(file_path.c_str(), "wb");  // mở tệp và lưu dl
            if (file == nullptr) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cerr << "  ERROR-KHONG mo duoc File de doc" << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                closesocket(client_socket);
            }
            else cout << "  =>Y: Da mo duoc file de doc." << endl;

            while (true) {
                memset(buffer, 0, sizeof(buffer));  //làm rỗng buffer rỗng để nhận dl
                int bytesRead = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
                if (bytesRead == SOCKET_ERROR) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    std::cerr << "  ERROR-KHONG nhan duoc du lieu File: " << WSAGetLastError() << std::endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
                else cout << "  =>Y: Da nhan duoc du lieu File." << endl;

                if (bytesRead == 0) {
                    // client mất kết nối
                    break;
                }

                size_t bytesWritten = fwrite(buffer, 1, bytesRead, file);
                if (bytesWritten < bytesRead) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    std::cerr << "  ERROR-KHONG luu duoc File" << std::endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                    const char* response = "SERVER luu tep KHONG thanh cong.";
                    int responseLength = strlen(response);
                    if (send(client_socket, response, responseLength, 0) == SOCKET_ERROR) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        std::cerr << "  ERROR-KHONG the phan hoi: " << WSAGetLastError() << std::endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                    break;
                }
                else {
                    cout << "  =>Y: Da luu duoc File." << endl;
                    fclose(file);
                    std::cout << "  =>Y: Hoan thanh nhan File: " << ten_tep << std::endl;

                    const char* response = "Luu tep thanh cong.";
                    int responseLength = strlen(response);
                    if (send(client_socket, response, responseLength, 0) == SOCKET_ERROR) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
                        std::cerr << "  ERROR-KHONG the phan hoi: " << WSAGetLastError() << std::endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }

                }
            }

            closesocket(client_socket);
            cout << "Ket thuc lan: ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); 
            cout<< cont << endl << endl; cont++;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        closesocket(wsocket);  //hoàn thành và giải phóng tài nguyên
        WSACleanup();  // giải phóng tài nguyên cấp phát bởi Winsock
    
    return 0;
}