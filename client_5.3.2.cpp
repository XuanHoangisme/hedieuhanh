#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <Winsock2.h>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <windows.h>
#include <string.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

#define BUFFER_SIZE 37020

void tai_tep_moi();
bool da_thuc_thi = false;
void dong_bo();
void theo_doi_thay_doi();
void hien_thi_danh_sach();

string danh_sach[20][2];
int dem_tep = 0;

int main() {
    thread tt1(theo_doi_thay_doi);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "                      ____________________________________" << endl;
    cout << "                     |  ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "DROPBOX - CLIENT: PHAN MAY KHACH";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "  | " << endl;
    cout << "                     |____________________________________|" << endl << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int lan = 1;
    char cont;
    while (true)
    {
        cout << " ___________________________________________________________________________" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "|                    |";
        cout << " Chuc nang 1: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Chon tep moi ban muon dong bo";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " | Bam ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "'a'";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " |" << endl;
        cout << "| LUA CHON CONG VIEC |______________________________________________________|" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "|                    | Chuc nang 3: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Hien thi danh sach tep da luu";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " | Bam ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "'c'";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " |" << endl;
        cout << "|____________________|______________________________________________________|" << endl;
        cout << "| Lua chon cua ban la|  ";
        char lua_chon; cin >> lua_chon;


        switch (lua_chon)
        {
        case 'a':
        {
            cout << "|____________________|_____|" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "____________________________________________________________________________" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            tai_tep_moi();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "                                                        ____________________" << endl;
            cout << "                                                       /";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << " KET THUC CONG VIEC";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << " |" << endl;
            cout << " _____________________________________________________/_____________________| " << lan << endl << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            lan++;
            break;
        }
        case 'b':
        {
            cout << "|____________________|_____|" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "____________________________________________________________________________" << endl;
            cout << "| ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "CHUC NANG 2: DONG BO TEP";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << " /" << endl;
            cout << "|_________________________/" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            dong_bo();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "                                                        ____________________" << endl;
            cout << "                                                       /";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << " KET THUC CONG VIEC";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << " |" << endl;
            cout << " _____________________________________________________/_____________________| " << lan << endl << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            lan++;
            break;
        }
        case 'c':
        {
            cout << "|____________________|_____|" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "____________________________________________________________________________" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            hien_thi_danh_sach();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "                                                        ____________________" << endl;
            cout << "                                                       /";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << " KET THUC CONG VIEC";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << " |" << endl;
            cout << " _____________________________________________________/_____________________| " << lan << endl << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            lan++;
            break;
        }
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "ERROR: Lua chon khong hop le!" << endl;
        }
        if (da_thuc_thi)
        {
            break;
        }
    }
    return 0;
}


void tai_tep_moi() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "| ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "CHUC NANG 1: ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout << "TAI TEP MOI";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << " /" << endl;
    cout << "|_________________________/" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "          - Dien ten tep:           ";
    string ten_tep; cin >> ten_tep;
    cout << "          - Dien dia chi tep moi:   ";
    string dchi_tep; cin >> dchi_tep;
    cout << "          __________________________________________________________________" << endl;

    // Khởi tạo Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cerr << "          ERROR-Khong the khoi tao Winsock! Ma loi: " << wsOK << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return;
    }
    else
    {
        cout << "          => Khoi tao Winsock thanh cong." << endl;

        // Tạo socket cho client
        SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == INVALID_SOCKET)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cerr << "          ERROR-Khong the tao socket! Ma loi: " << WSAGetLastError() << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            closesocket(clientSocket);
            WSACleanup();
            return;
        }
        else
        {
            cout << "          => Tao socket thanh cong." << endl;

            // Thiết lập địa chỉ server
            SOCKADDR_IN serverAddr;
            serverAddr.sin_family = AF_INET;
            serverAddr.sin_port = htons(8080); // Sử dụng cổng 8080
            serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Địa chỉ IP của server - CÙng máy tính

            // Kết nối tới server
            if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cerr << "          ERROR-Khong the ket noi toi server! Ma loi: " << WSAGetLastError() << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                closesocket(clientSocket);
                WSACleanup();
                return;
            }
            else
            {
                cout << ("          => Ket noi toi Server thanh cong") << endl;

                ifstream tep(dchi_tep, ios::binary | ios::ate);
                if (!tep)
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cerr << "          ERROR-Khong the mo tep." << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    closesocket(clientSocket);
                    WSACleanup();
                    return;
                }
                else
                {
                    streamsize tep_size = tep.tellg();
                    tep.seekg(0, ios::beg);

                    cout << "          => Dang gui tep tin: " << ten_tep << std::endl;
                    if (send(clientSocket, ten_tep.c_str(), ten_tep.size(), 0) == SOCKET_ERROR) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        std::cerr << "          ERROR-Khong the gui ten tep tin" << std::endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        closesocket(clientSocket);
                        WSACleanup();
                        return;
                    }
                    else
                    {
                        char buffer[1024];
                        while (tep_size > 0)
                        {
                            streamsize bytesRead = tep.read(buffer, sizeof(buffer)).gcount();
                            if (send(clientSocket, buffer, bytesRead, 0) == SOCKET_ERROR)
                            {
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                std::cerr << "          ERROR-Khong the gui du lieu tep tin" << std::endl;
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                closesocket(clientSocket);
                                WSACleanup();
                                break;
                            }
                            else
                            {
                                std::cout << "          => Gui du lieu thanh cong" << std::endl;
                                tep_size -= bytesRead;

                                char response[1024];
                                int responseLength = recv(clientSocket, response, sizeof(response) - 1, 0);
                                if (responseLength == SOCKET_ERROR)
                                {
                                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                    std::cerr << "          ERROR-Khong the nhan phan hoi tu server" << std::endl;
                                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                    closesocket(clientSocket);
                                    WSACleanup();
                                    return;
                                }
                                else
                                {
                                    cout << "          __________________________________________________________________" << endl;
                                    response[responseLength] = '\0';
                                    std::cout << "          - Phan hoi tu server: ";

                                    cout << response << std::endl;

                                    danh_sach[dem_tep][0] = ten_tep; //ten tep cho vao danh sach
                                    danh_sach[dem_tep][1] = dchi_tep; //dia chi tep vao danh sach

                                    dem_tep++;

                                    closesocket(clientSocket);
                                    WSACleanup();
                                    return;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    da_thuc_thi = true;
}


void hien_thi_danh_sach() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "|";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "CHUC NANG 3: ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "DANH SACH TEP DA DONG BO";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << " /" << endl;
    cout << "|_____________________________________/" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "          Tong: " << dem_tep << endl;
    cout << "          __________________________________________________________________" << endl;
    for (int i = 0; i < dem_tep; i++) {
        cout << "          | So " << i + 1 << ": ";
        cout << "+ Ten tep: " << danh_sach[i][0] << endl;
        cout << "          |       + Dia chi: " << danh_sach[i][1] << endl;
        cout << "          |_________________________________________________________________" << endl;
    }

}


void theo_doi_thay_doi() {
    while (true)
    {
        //dường dẫn đến tệp cần theo dõi
            LPCWSTR filePath = L"D:\\client_HDH\\tep.txt";
            //khai báo con trỏ ko thay đổi trỏ đến một chuỗi ký tự tự động, đại diện đường dẫn

            //tạo cờ HANDLE theo dõi sự thay đổi
        HANDLE changeNotification = FindFirstChangeNotification(
            L"D:\\client_HDH\\",    //đường dẫn cần theo dõi
            FALSE,      //theo dõi tất cả các sự kiện thay đổi
            FILE_NOTIFY_CHANGE_LAST_WRITE   // theo dõi sự thay đổi khi tệp được ghi
        );

        //kiểm tra cờ thông báo thay đổi có hợp lệ hay không
        if (changeNotification == INVALID_HANDLE_VALUE) {
            cerr << "Khong the bat dau theo doi thay doi. Loi: " << GetLastError() << endl;
            break;
        }

        //hiển thị thông báo bắt đầu theo dõi
        //cout << "Da bat dau theo doi thay doi cho 'client_HDH' tren o dia D.\n";

        //vòng lặp để theo dõi thay đổi liên tục
        while (true)
        {
            //đợi sự kiện thay đổi
            if (WaitForSingleObject(changeNotification, INFINITE) == WAIT_OBJECT_0) {
                //kiểm tra tep.txt đã thay đổi chưa
                DWORD waitResult = WaitForSingleObject(changeNotification, 0);

                if (waitResult == WAIT_OBJECT_0) 
                {
                    //hiển thị tbao khi có sự tđ
                    //cout << "Tep.txt da co su thay doi!\n";
                    //dong_bo();   //gọi hàm đồng bộ
                    {
                        int i = 0;
                        while (i < dem_tep)
                        {
                            //cout << " Lan: " << i + 1 << endl;
                            string ten_tep = danh_sach[i][0];
                            string dchi_tep = danh_sach[i][1];
                            //cout << "Dong bo tep :" << ten_tep << ". Ket qua: " << endl;
                            // Khởi tạo Winsock
                            WSADATA wsData;
                            WORD ver = MAKEWORD(2, 2);
                            int wsOK = WSAStartup(ver, &wsData);
                            if (wsOK != 0)
                            {
                                //cerr << "O-Khong the khoi tao Winsock! Ma loi: " << wsOK << endl;
                                break;
                            }
                            else
                            {
                                //cout << "CO-Khoi tao Winsock thanh cong." << endl;

                                // Tạo socket cho client
                                SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
                                if (clientSocket == INVALID_SOCKET)
                                {
                                    //cerr << "O-Khong the tao socket! Ma loi: " << WSAGetLastError() << endl;
                                    closesocket(clientSocket);
                                    WSACleanup();
                                    break;
                                }
                                else
                                {
                                    //cout << "CO-Tao socket thanh cong." << endl;

                                    // Thiết lập địa chỉ server
                                    SOCKADDR_IN serverAddr;
                                    serverAddr.sin_family = AF_INET;
                                    serverAddr.sin_port = htons(8080); // Sử dụng cổng 8080
                                    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Địa chỉ IP của server - CÙng máy tính

                                    // Kết nối tới server
                                    if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
                                    {
                                        //cerr << "O-Khong the ket noi toi server! Ma loi: " << WSAGetLastError() << endl;
                                        closesocket(clientSocket);
                                        WSACleanup();
                                        break;
                                    }
                                    else
                                    {
                                        //cout << ("V-Ket noi toi Server thanh cong") << endl;

                                        std::ifstream tep(dchi_tep, std::ios::binary | std::ios::ate);
                                        if (!tep)
                                        {
                                            //cerr << "O-Khong the mo tep." << endl;
                                            closesocket(clientSocket);
                                            WSACleanup();
                                            break;
                                        }
                                        else
                                        {
                                            std::streamsize tep_size = tep.tellg();
                                            tep.seekg(0, std::ios::beg);

                                            //cout << "Dang gui tep tin: " << ten_tep << std::endl;
                                            if (send(clientSocket, ten_tep.c_str(), ten_tep.size(), 0) == SOCKET_ERROR) {
                                                //std::cerr << "Khong the gui ten tep tin" << std::endl;
                                                closesocket(clientSocket);
                                                WSACleanup();
                                                break;
                                            }
                                            else
                                            {
                                                char buffer[1024];
                                                while (tep_size > 0)
                                                {
                                                    std::streamsize bytesRead = tep.read(buffer, sizeof(buffer)).gcount();
                                                    if (send(clientSocket, buffer, bytesRead, 0) == SOCKET_ERROR)
                                                    {
                                                        //std::cerr << "Khong the gui du lieu tep tin" << std::endl;
                                                        closesocket(clientSocket);
                                                        WSACleanup();
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        //std::cout << "Gui du lieu thanh cong" << std::endl;
                                                        tep_size -= bytesRead;

                                                        char response[1024];
                                                        int responseLength = recv(clientSocket, response, sizeof(response) - 1, 0);
                                                        if (responseLength == SOCKET_ERROR)
                                                        {
                                                            //std::cerr << "Khong the nhan phan hoi tu server" << std::endl;
                                                            closesocket(clientSocket);
                                                            WSACleanup();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            response[responseLength] = '\0';
                                                            //std::cout << "Phan hoi tu server: " << response << std::endl;
                                                            //closesocket(clientSocket);
                                                            //WSACleanup();
                                                            //return; 
                                                            break;
                                                        }

                                                    }
                                                }
                                            }
                                        } closesocket(clientSocket);
                                    }
                                }
                            } i++;
                        } WSACleanup();
                    }
                    //đặt lại cờ tbao để chờ cbi cho tđ tiếp
                    if (!FindNextChangeNotification(changeNotification)) {
                        //cerr << "Khong the tim thay su kien thay doi tiep theo. Loi: " << GetLastError() << endl;
                        break;
                    }
                }
                else if (waitResult == WAIT_TIMEOUT) {
                    //sự kiện tđ đã xảy ra nhưng chưa được đặt lại => đặt lại nó để tiếp tục theo dõi
                    if (!FindNextChangeNotification(changeNotification)) {
                        //cerr << "Khong the tim thay su kien thay doi tiep theo. Loi: " << GetLastError() << endl;
                        break;
                    }
                }
                else {
                    //cerr << "WaitForSingleObject tra ve loi: " << GetLastError() << endl;
                    break;
                }
            }
            else {
                //cerr << "WaitForSingleObject tra ve loi: " << GetLastError() << endl;
                break;
            }

        }
        //đóng cờ tbao khi kết thúc ctrinh
        FindCloseChangeNotification(changeNotification);
        this_thread::sleep_for(chrono::seconds(5)); //cứ 1s thực hiện quét 1 lần
    }
}


void dong_bo()
{

    cout << "  Chuc nang 2: Dong bo tep moi " <<dem_tep<< endl << endl;
    int i = 0;
    while(i < dem_tep)
    {
        cout << "  Lan: " << i + 1 << endl;
        string ten_tep = danh_sach[i][0];
        string dchi_tep = danh_sach[i][1];
        cout << "  Dong bo tep :" << ten_tep << ". Ket qua: " << endl;
        // Khởi tạo Winsock
        WSADATA wsData;
        WORD ver = MAKEWORD(2, 2);
        int wsOK = WSAStartup(ver, &wsData);
        if (wsOK != 0)
        {
            cerr << "O-Khong the khoi tao Winsock! Ma loi: " << wsOK << endl;
            return;
        }
        else
        {
            cout << "  =>Y: Khoi tao Winsock thanh cong." << endl;

            // Tạo socket cho client
            SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
            if (clientSocket == INVALID_SOCKET)
            {
                cerr << "O-Khong the tao socket! Ma loi: " << WSAGetLastError() << endl;
                closesocket(clientSocket);
                WSACleanup();
                return;
            }
            else
            {
                cout << "  =>Y: Tao socket thanh cong." << endl;

                // Thiết lập địa chỉ server
                SOCKADDR_IN serverAddr;
                serverAddr.sin_family = AF_INET;
                serverAddr.sin_port = htons(8080); // Sử dụng cổng 8080
                serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Địa chỉ IP của server - CÙng máy tính

                // Kết nối tới server
                if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
                {
                    cerr << "O-Khong the ket noi toi server! Ma loi: " << WSAGetLastError() << endl;
                    closesocket(clientSocket);
                    WSACleanup();
                    return;
                }
                else
                {
                    cout << ("  =>Y: Ket noi toi Server thanh cong") << endl;

                    ifstream tep(dchi_tep, ios::binary | ios::ate);
                    if (!tep)
                    {
                        cerr << "O-Khong the mo tep." << endl;
                        closesocket(clientSocket);
                        WSACleanup();
                        return;
                    }
                    else
                    {
                        streamsize tep_size = tep.tellg();
                        tep.seekg(0, ios::beg);

                        cout << "  =>Y: Dang gui tep tin: " << ten_tep << std::endl;
                        if (send(clientSocket, ten_tep.c_str(), ten_tep.size(), 0) == SOCKET_ERROR) {
                            std::cerr << "Khong the gui ten tep tin" << std::endl;
                            closesocket(clientSocket);
                            WSACleanup();
                            return;
                        }
                        else
                        {
                            char buffer[1024];
                            while (tep_size > 0)
                            {
                                streamsize bytesRead = tep.read(buffer, sizeof(buffer)).gcount();
                                if (send(clientSocket, buffer, bytesRead, 0) == SOCKET_ERROR)
                                {
                                    std::cerr << "Khong the gui du lieu tep tin" << std::endl;
                                    closesocket(clientSocket);
                                    WSACleanup();
                                    break;
                                }
                                else
                                {
                                    std::cout << "  =>Y: Gui du lieu thanh cong" << std::endl;
                                    tep_size -= bytesRead;

                                    char response[1024];
                                    int responseLength = recv(clientSocket, response, sizeof(response) - 1, 0);
                                    if (responseLength == SOCKET_ERROR)
                                    {
                                        std::cerr << "Khong the nhan phan hoi tu server" << std::endl;
                                        closesocket(clientSocket);
                                        WSACleanup();
                                        return;
                                    }
                                    else
                                    {
                                        response[responseLength] = '\0';
                                        std::cout << "  =>Y: Phan hoi tu server: " << response << std::endl;
                                        //closesocket(clientSocket);
                                        //WSACleanup();
                                        //return; 
                                        break;
                                    }

                                }
                            }
                        }
                    } closesocket(clientSocket);
                }
            }
        } i++;
    } WSACleanup();
}