#include <vector>
#include <string>
#include <fstream>
#include "lexical_analizer.h"

using namespace std;

int main(){

    // Inicialización de los estados.
    vector<state> states(69);

    states[0] = state(0, false);
    states[1] = state(1, false);
    states[2] = state(2, true);
    states[3] = state(3, false);
    states[4] = state(4, false);
    states[5] = state(5, true);
    states[6] = state(6, false);
    states[7] = state(7, true);
    states[8] = state(8, true);
    states[9] = state(9, false);

    states[10] = state(10, false);
    states[11] = state(11, false);
    states[12] = state(12, false);
    states[13] = state(13, true);
    states[14] = state(14, false);
    states[15] = state(15, false);
    states[16] = state(16, false);
    states[17] = state(17, true);
    states[18] = state(18, false);
    states[19] = state(19, false);

    states[20] = state(20, false);
    states[21] = state(21, false);
    states[22] = state(22, true);
    states[23] = state(23, true);
    states[24] = state(24, false);
    states[25] = state(25, false);
    states[26] = state(26, true);
    states[27] = state(27, false);
    states[28] = state(28, true);
    states[29] = state(29, false);

    states[30] = state(30, true);
    states[31] = state(31, false);
    states[32] = state(32, true);
    states[33] = state(33, false);
    states[34] = state(34, true);
    states[35] = state(35, false);
    states[36] = state(36, true);
    states[37] = state(37, false);
    states[38] = state(38, true);
    states[39] = state(39, false);

    states[40] = state(40, true);
    states[41] = state(41, false);
    states[42] = state(42, true);
    states[43] = state(43, false);
    states[44] = state(44, true);
    states[45] = state(45, false);
    states[46] = state(46, true);
    states[47] = state(47, false);
    states[48] = state(48, false);
    states[49] = state(49, true);

    states[50] = state(50, false);
    states[51] = state(51, false);
    states[52] = state(52, true);
    states[53] = state(53, false);
    states[54] = state(54, true);
    states[55] = state(55, false);
    states[56] = state(56, true);
    states[57] = state(57, false);
    states[58] = state(58, true);
    states[59] = state(59, false);

    states[60] = state(60, true);
    states[61] = state(61, false);
    states[62] = state(62, true);
    states[63] = state(63, false);
    states[64] = state(64, true);
    states[65] = state(65, false);
    states[66] = state(66, true);
    states[67] = state(67, false);
    states[68] = state(68, true);

    lexical_analizer analizer(states, "src/delta.in", &states[0], "test", "src/reserved_words.in");

    analizer.execute();

    return 0;
}