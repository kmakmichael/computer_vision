function [c, pairs] = correspondences()
    c = cell(12,12);
    pairs = [6 5; 7 9; 5 3; 5 4; 9 10; 1 12; 2 7; 1 11; 1 7; 7 8; 7 5];
    
    % x' -> x (x' = Hx) (moving -> fixed)
        
    % 6 -> 5
    c(6,5) = {[109,157; 104,210; 103,185; 137,265; 157,283; 182,263; 180,282; 236,282; 275,282; 276,220; 237,223; 239,200; 276,195; 239,141; 278,136; 298,105; 262,81; 108,80; 129,123; 204,112; 158,86; 180,82; 156,123; 180,119; 136,148; 194,142; 186,196; 160,154; 166,197; 137,202]};
    c(5,6) = {[173,94; 169,148; 168,123; 203,202; 223,219; 249,199; 247,217; 302,217; 341,216; 340,154; 302,159; 304,136; 342,131; 305,77; 343,70; 367,38; 325,14; 171,18; 194,60; 266,48; 220,21; 244,18; 218,60; 243,57; 200,88; 258,78; 252,133; 224,92; 232,133; 202,141]}; 

    % 7 -> 9 
    c(7,9) = {[201,151; 218,150; 202,158; 217,157; 205,160; 215,160; 205,181; 214,181; 204,184; 215,183; 231,148; 249,147; 232,155; 248,154; 236,158; 246,158; 235,179; 246,179; 235,181; 246,181; 365,110; 377,109; 369,113; 373,113; 369,120; 373,120; 369,123; 373,123; 369,129; 374,129]};
    c(9,7) = {[50,239; 65,238; 50,246; 65,246; 53,249; 63,249; 52,269; 62,269; 51,272; 61,272; 81,237; 98,236; 82,244; 97,243; 85,246; 95,246; 83,267; 94,267; 82,270; 93,270; 213,202; 225,201; 217,205; 221,205; 217,212; 221,212; 217,215; 221,215; 217,221; 221,221]};

    % 5 -> 3
    c(5,3) = {[276,280;  276,272; 308,265; 317,264;  327,264; 309,213; 318,213; 338,212; 328,213; 309,189; 309,168; 319,168; 328,166; 338,187; 342,160; 254,194; 255,187; 247,236; 239,236; 220,237; 206,156; 199,85; 199,91; 258,84; 233,115; 199,85; 199,92; 258,77; 258,84; 225,93]};
    c(3,5) = {[114,202; 113,195; 144,186; 153,186; 163,185; 145,136; 154,136; 173,135; 164,135; 145,112; 145,92; 155,91; 164,90; 173,110; 178,84; 91,118; 92,111; 84,160; 75,160; 57,162; 42,81; 33,9; 33,14; 93,7; 68,39; 33,7; 32,15; 93,1; 93,6; 60,15]};

    % 5 -> 4
    c(4,5) = {[160,23; 177,20; 195,17; 160,65; 177,63; 194,60; 264,11; 283,7; 264,56; 283,53; 200,128; 200,165; 263,140; 263,94; 291,92; 291,139; 183,166; 182,131; 154,69; 155,19; 158,168; 165,131; 262,192; 281,191; 290,191; 183,150; 177,42; 264,34; 195,40; 283,32]};
    c(5,4) = {[209,95; 226,93; 243,90; 207,136; 225,134; 242,132; 311,85; 330,82; 310,129; 330,127; 247,199; 246,236; 309,213; 309,168; 338,166; 338,212; 229,236; 229,200; 202,140; 204,92; 203,238; 212,202; 308,265; 327,264; 337,264; 229,220; 224,115; 311,108; 243,112; 330,105]};

    % 9 -> 10
    c(9,10) = {[157,33; 252,21; 165,56; 102,143; 161,165; 246,185; 178,79; 200,77; 222,74; 163,108; 163,127; 162,132; 273,67; 246,100; 246,120; 247,125; 163,81; 247,73; 188,78; 211,76; 233,74; 246,46; 174,164; 162,104; 247,96; 265,132; 266,75; 158,38; 159,87; 249,77]};
    c(10,9) = {[151,123; 248,113; 160,146; 93,234; 153,259; 241,281; 173,170; 195,168; 218,166; 157,199; 157,219; 156,223; 270,159; 242,192; 242,213; 243,218; 158,172; 243,165; 184,170; 206,167; 229,165; 243,137; 167,257; 156,195; 243,188; 261,226; 263,167; 154,127; 154,177; 245,169]};

    % 1 -> 12
    c(1,12) = {[118,52; 128,52; 159,49; 149,49; 112,89; 131,88; 112,142; 131,142; 149,91; 159,91; 149,136; 159,136; 116,213; 126,213; 218,261; 232,244; 250,222; 244,218; 117,115; 127,115; 149,113; 159,113; 129,186; 113,185; 369,44; 315,52; 344,64; 364,85; 363,72; 380,102]}; 
    c(12,1) = {[72,9; 82,9; 115,7; 104,7; 66,46; 85,46; 66,102; 84,102; 104,49; 114,49; 104,96; 114,96; 69,173; 79,173; 172,221; 187,205; 205,183; 199,178; 70,75; 80,75; 103,73; 113,73; 82,147; 67,145; 326,4; 273,12; 301,24; 320,45; 319,33; 335,62]};

    % 2 -> 7
    c(2,7) = {[125,129; 114,108; 125,106; 114,84; 160,132; 158,82; 147,82; 140,133; 157,105; 189,118; 107,165; 126,164; 112,193; 140,162; 158,162; 156,190; 109,74; 23,134; 19,106; 10,84; 20,82; 16,169; 15,192; 8,106; 68,55; 42,60; 45,48; 135,51; 219,30; 212,43; 241,23; 210,35; 7,13; 145,106; 226,50; 280,72; 247,50; 262,54; 258,62; 275,33; 288,32; 276,56; 289,57]};
    c(7,2) = {[214,204; 204,184; 214,182; 204,160; 248,207; 246,158; 236,159; 229,208; 245,180; 279,190; 197,240; 216,239; 202,268; 229,239; 247,237; 245,266; 199,150; 115,210; 113,182; 105,162; 115,159; 109,245; 109,267; 103,183; 160,135; 136,136; 139,125; 224,127; 308,108; 300,121; 330,101; 229,111; 104,95; 235,183; 355,126; 370,151; 336,128; 350,131; 347,140; 365,109; 377,109; 365,134; 378,133]};

    % 1 -> 11
    c(1,11) = {[118,7; 128,6; 150,4; 160,3; 118,27; 128,27; 150,25; 160,25; 118,32; 128,30; 369,44; 314,183; 314,189; 316,52; 117,93; 127,92; 149,90; 159,90; 117,114; 127,114; 149,112; 159,112; 117,117; 117,138; 232,145; 231,58; 255,156; 111,186; 129,185; 149,189]};
    c(11,1) = {[46,94; 57,94; 79,92; 89,92; 46,114; 56,114; 79,112; 89,112; 46,118; 56,117; 296,136; 242,274; 242,281; 244,142; 43,180; 53,179; 76,179; 86,178; 42,202; 53,202; 76,199; 86,201; 42,205; 41,226; 159,235; 160,147; 183,246; 33,277; 52,276; 73,280]};

    % 1 -> 7
    c(1,7) = {[118,7; 128,7; 118,28; 128,28; 118,52; 128,52; 150,4; 160,3; 150,25; 160,25; 150,50; 160,49; 117,93; 127,92; 117,114; 127,114; 149,90; 159,90; 149,111; 159,110; 13,6; 22,6; 13,28; 22,27; 13,52; 22,52; 73,41; 282,50; 242,94; 273,14]};
    c(7,1) = {[205,160; 215,160; 205,181; 215,181; 205,205; 214,204; 236,158; 246,157; 235,179; 245,179; 236,203; 245,202; 203,245; 212,243; 203,266; 212,266; 234,243; 245,242; 234,264; 244,264; 105,161; 114,160; 105,181; 114,181; 104,205; 113,204; 161,193; 369,203; 328,249; 358,168]};

    % 7 -> 8
    c(7,8) = {[160,134; 309,103; 336,127; 330,102; 309,38; 353,68; 355,126; 369,151; 201,151; 250,147; 201,267; 245,265; 326,157; 345,175; 328,249; 343,257; 248,54; 296,103; 160,193; 368,204]};
    c(8,7) = {[18,127; 170,98; 195,122; 189,97; 170,34; 213,66; 215,123; 228,147; 60,145; 110,142; 58,262; 102,259; 185,153; 204,171; 186,243; 200,252; 110,48; 155,99; 17,187; 226,200]};

    % 7 -> 5
    c(5,7) = {[253,55; 360,56; 338,125; 249,196; 294,69; 340,161; 304,164; 338,190; 254,55; 254,153; 319,8; 378,56; 227,57; 232,92; 308,188; 357,38; 304,45; 315,44; 326,17; 305,132]};
    c(7,5) = {[31,131; 134,139; 112,204; 20,274; 70,147; 112,240; 77,242; 109,267; 31,131; 18,230; 98,89; 151,137; 3,131; 7,167; 80,265; 132,120; 82,123; 92,123; 104,97; 79,209]};
end