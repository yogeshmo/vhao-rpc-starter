#include "client.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "ERROR: Usage is './client <port>'" << endl;
        return 0;
    }
    int port = atoi(argv[1]);

    list<string> memes;
    memes.push_back("ben reeBes");
    memes.push_back("meeshon failed");
    memes.push_back("haha jk... unLESS?");

    // Before appending 'F'.
    printList(memes);
    memes = client_append(port, memes, 'F');

    // After appending 'F'.
    printList(memes);

    return 0;
}