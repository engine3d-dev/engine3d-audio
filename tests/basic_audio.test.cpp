#include <boost/ut.hpp>
import audio;

boost::ut::suite<"basic_test"> add_test = []() {
    using namespace boost::ut;

    //! @note This is just a dummy test case for setting up test cases
    "add"_test = []() {
        int x = 100;
        int y = 200;
        int z = (x + y);

        expect(z == 300);
        z -= 100;
        expect(z == 200);
    };

    "subtract"_test = []() {
        int x = 100;
        int y = 200;
        int z = (x + y);

        z -= 200;
        expect(z == 100);
    };

    "audio::test"_test = []() {
        audio::sound sound = audio::sound("test.wav");
    };
};