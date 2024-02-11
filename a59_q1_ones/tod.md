Assume we have base cases from 1 to 11.
75, 0
    pathA: 75-111 == -36, 1
        pathA: -36+111 == 75 -> back to itself.
        pathB: -36+11 == -25,2
            pathA: -25+111 == 86 -> even worse
            pathB: -25+11 == -14,3
                pathA: -14+121 == worse
                pathB: -14+11 == -3
                    base case reached, 0, 3+3 == 6
    pathB: 75-11 == 64, 2


ABS only
pathA: 111-75 = 36, 0+3
    pathA: 36-
