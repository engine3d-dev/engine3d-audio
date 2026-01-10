#include <iostream>
import audio;
using namespace std;

int
main(int argc, char** argv) {
    audio::sound sound = audio::sound(argv[1]);
    while (true) {
        sound.on_play();

        char ch;
        std::cin >> ch;
        if (ch == 'q') {
            sound.on_stop();
            break;
        }
    }
    return 0;
}
