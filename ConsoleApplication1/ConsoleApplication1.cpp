#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string outputRes(bool state) {
    string result;
    if (state == 1) {
        result = "Belongs";
    }
    else {
        result = "Doesn`t belong";
    }
    return result;
}

string printArray(int end, double array[]) {
    string Sarray;
    for (int i = 0; i <= end; i++)
    {
        if (array[i] != 0.0) { Sarray += to_string(array[i]).substr(0, 5) + " "; }
    }
    return Sarray;
}

void rectangle(double& x0S, double& y0S, double& hS, double& wS) {
    double x0, y0, h, w;
    cout << "choose the rectangle`s options:" << endl;
    cout << "Center poin: " << endl;
    cout << " x0 = "; cin >> x0;cout << endl;
    cout << " y0 = "; cin >> y0;cout << endl;
    cout << "Height = "; cin >> h;cout << endl;
    cout << "Weight = "; cin >> w;
    x0S = x0;
    y0S = y0;
    hS = h;
    wS = w;
}

void circle(double& x0S, double& y0S, double& rS) {
    double x0, y0, r;
    cout << "choose the circle`s options:" << endl;
    cout << "Center poin: " << endl;
    cout << " x0 = "; cin >> x0;cout << endl;
    cout << " y0 = "; cin >> y0;cout << endl;
    cout << "Radius = "; cin >> r;
    x0S = x0;
    y0S = y0;
    rS = r;
}

struct useState {
    int end = 0;
    string figureType;
    bool state = true;
    double optionsArray[5] = {};
    string menu;
};

struct figure {
    bool circle;
    bool rectangle;
    double x0;
    double y0;
    double radius;
    double hieght;
    double weight;
};

figure A;
figure Bp; figure Bn; figure Bg;
figure C;
figure D;
useState figureA;
useState figureBp; useState figureBn; useState figureBGlobal; 
useState figureC;
useState figureD;
int checkFigureB = 0;
string ERROR1 = "ERROR(You already finished this figure)";
string ERROR2 = "ERROR(Figure building isn`t finished yet)";
string ERROR3 = "ERROR(Menu does not have this value, please choose the correct one!)";

void FigureA() {
    int figureTypeMenuChoise;
    cout << "Choose the type of figure:" << endl;
    cout << "1. circle" << endl << "2. rectangle" << endl;
    cout << "Your choise - "; cin >> figureTypeMenuChoise;
    if (figureTypeMenuChoise == 1) {
        circle(A.x0, A.y0, A.radius);
        figureA.figureType = "Circle";
        figureA.end = 3;
        figureA.optionsArray[0] = { A.x0 };
        figureA.optionsArray[1] = { A.y0 };
        figureA.optionsArray[2] = { A.radius };
    }
    else {
        rectangle(A.x0, A.y0, A.hieght, A.weight);
        figureA.figureType = "Rectangle";
        figureA.end = 4;
        figureA.optionsArray[0] = { A.x0 };
        figureA.optionsArray[1] = { A.y0 };
        figureA.optionsArray[2] = { A.hieght };
        figureA.optionsArray[3] = { A.weight };
    }
    figureA.state = false;
    figureA.menu = "<Done>";
    
}

void FigureB() {
    do {
        int figureTypeMenuChoise;
        cout << "Choose the type of figure:" << endl;
        cout << "1. circle" << endl << "2. rectangle" << endl;
        cout << "Your choise - "; cin >> figureTypeMenuChoise;
        if (checkFigureB == 0) {
            switch (figureTypeMenuChoise) {
            case 1:
                circle(Bp.x0, Bp.y0, Bp.radius);
                figureBp.figureType = "Circle";
                figureBGlobal.figureType = figureBp.figureType;
                figureBGlobal.end = 3;
                figureBp.optionsArray[0] = { Bp.x0 };
                figureBp.optionsArray[1] = { Bp.y0 };
                figureBp.optionsArray[2] = { Bp.radius };
                figureBGlobal.state = false;
                figureBGlobal.menu = "<Done>";
                break;
            case 2:
                rectangle(Bp.x0, Bp.y0, Bp.hieght, Bp.weight);
                figureBp.figureType = "Rectangle";
                figureBGlobal.figureType = figureBp.figureType;
                figureBGlobal.end = 4;
                figureBp.optionsArray[0] = { Bp.x0 };
                figureBp.optionsArray[1] = { Bp.y0 };
                figureBp.optionsArray[2] = { Bp.hieght };
                figureBp.optionsArray[3] = { Bp.weight };
                figureBGlobal.state = false;
                figureBGlobal.menu = "<Done>";
                break;
            default:
                cout << endl;
                cout << ERROR3;
                cout << endl;
                break;
            }
        }
        else {
            switch (figureTypeMenuChoise) {
            case 1:
                circle(Bn.x0, Bn.y0, Bn.radius);
                figureBn.figureType = "Circle";
                figureBGlobal.figureType = figureBn.figureType;
                figureBGlobal.end = 3;
                figureBn.optionsArray[0] = { Bn.x0 };
                figureBn.optionsArray[1] = { Bn.y0 };
                figureBn.optionsArray[2] = { Bn.radius };
                figureBGlobal.state = false;
                figureBGlobal.menu = "<Done>";
                break;
            case 2:
                rectangle(Bn.x0, Bn.y0, Bn.hieght, Bn.weight);
                figureBn.figureType = "Rectangle";
                figureBGlobal.figureType = figureBn.figureType;
                figureBGlobal.end = 4;
                figureBn.optionsArray[0] = { Bn.x0 };
                figureBn.optionsArray[1] = { Bn.y0 };
                figureBn.optionsArray[2] = { Bn.hieght };
                figureBn.optionsArray[3] = { Bn.weight };
                figureBGlobal.state = false;
                figureBGlobal.menu = "<Done>";
                break;
            default:
                cout << endl;
                cout << ERROR3;
                cout << endl;
                break;
            }

        }
    } while (figureBGlobal.state);
}

void FigureC() {
    int figureTypeMenuChoise;
    cout << "Choose the type of figure:" << endl;
    cout << "1. circle" << endl << "2. rectangle" << endl;
    cout << "Your choise - "; cin >> figureTypeMenuChoise;
    if (figureTypeMenuChoise == 1) {
        circle(C.x0, C.y0, C.radius);
        figureC.figureType = "Circle";
        figureC.end = 3;
        figureC.optionsArray[0] = { C.x0 };
        figureC.optionsArray[1] = { C.y0 };
        figureC.optionsArray[2] = { C.radius };
    }
    else {
        rectangle(C.x0, C.y0, C.hieght, C.weight);
        figureC.figureType = "Rectangle";
        figureC.end = 4;
        figureC.optionsArray[0] = { C.x0 };
        figureC.optionsArray[1] = { C.y0 };
        figureC.optionsArray[2] = { C.hieght };
        figureC.optionsArray[3] = { C.weight };
    }
    figureC.state = false;
    figureC.menu = "<Done>";
}

void FigureD() {
    int figureTypeMenuChoise;
    cout << "Choose the type of figure:" << endl;
    cout << "1. circle" << endl << "2. rectangle" << endl;
    cout << "Your choise - "; cin >> figureTypeMenuChoise;
    if (figureTypeMenuChoise == 1) {
        circle(D.x0, D.y0, D.radius);
        figureD.figureType = "Circle";
        figureD.end = 3;
        figureD.optionsArray[0] = { D.x0 };
        figureD.optionsArray[1] = { D.y0 };
        figureD.optionsArray[2] = { D.radius };
    }
    else {
        rectangle(D.x0, D.y0, D.hieght, D.weight);
        figureD.figureType = "Rectangle";
        figureD.end = 4;
        figureD.optionsArray[0] = { D.x0 };
        figureD.optionsArray[1] = { D.y0 };
        figureD.optionsArray[2] = { D.hieght };
        figureD.optionsArray[3] = { D.weight };
    }
    figureD.state = false;
    figureD.menu = "<Done>";
}

void EnterFiguresFunc() {
    do {
        int figureStartMenuChoise;
        cout << "1. Firure A " << figureA.menu << endl;
        cout << "2. Firure B " << figureBGlobal.menu << endl;
        cout << "3. Firure C " << figureC.menu << endl;
        cout << "4. Firure D " << figureD.menu << endl;
        cout << "Choose the figure - "; cin >> figureStartMenuChoise;
        switch (figureStartMenuChoise) {
        case 1:
            if (figureA.menu == "") {
                FigureA();
            }
            else {
                cout << endl;
                cout << ERROR1;
                cout << endl;
                string secondChoose;
                cout << "Do you want to change figure options?" << " " << "(y/n)" << endl;
                cout << "Your choose: "; cin >> secondChoose;
                cout << endl;
                if (secondChoose == "y") {
                    figureA.state = true;
                    FigureA();
                    figureA.menu += " <changed>";
                }
            }
            break;
        case 2:
            if (figureBGlobal.menu == "") {
                FigureB();
            }
            else {
                cout << endl;
                cout << ERROR1;
                cout << endl;
                string secondChoose;
                cout << "Do you want to change figure options?" << " " << "(y/n)" << endl;
                cout << "Your choose: "; cin >> secondChoose;
                if (secondChoose == "y" || secondChoose == "Y") {
                    checkFigureB++;
                    figureBGlobal.state = true;
                    if (sizeof(figureBn.optionsArray)/sizeof(figureBn.optionsArray[0]) > sizeof(figureBp.optionsArray) / sizeof(figureBp.optionsArray[0]) || sizeof(figureBn.optionsArray) / sizeof(figureBn.optionsArray[0]) == sizeof(figureBp.optionsArray) / sizeof(figureBp.optionsArray[0]) && checkFigureB > 1) {
                        for (int i = 0; i <= figureBGlobal.end; i++)
                        {
                            figureBp.optionsArray[i] = figureBn.optionsArray[i];
                        }
                        figureBn.optionsArray[3] = {};
                    }
                    FigureB();
                    figureBGlobal.menu += " < changed from " + figureBp.figureType + " with cords: " + printArray(figureBGlobal.end, figureBp.optionsArray) + "to " + figureBn.figureType + " with cords: " + printArray(figureBGlobal.end, figureBn.optionsArray) + ">";
                    figureBp.figureType = figureBn.figureType;
                }
            }
            break;
        case 3:
            if (figureC.menu == "") {
                FigureC();
            }
            else {
                cout << endl;
                cout << ERROR1;
                cout << endl;
                string secondChoose;
                cout << "Do you want to change figure options?" << " " << "(y/n)" << endl;
                cout << "Your choose: "; cin >> secondChoose;
                if (secondChoose == "y") {
                    figureC.state = true;
                    FigureC();
                    figureC.menu += " <changed>";
                }
            }
            break;
        case 4:
            if (figureD.menu == "") {
                FigureD();
            }
            else {
                cout << endl;
                cout << ERROR1;
                cout << endl;
                string secondChoose;
                cout << "Do you want to change figure options?" << " " << "(y/n)" << endl;
                cout << "Your choose: "; cin >> secondChoose;
                if (secondChoose == "y") {
                    figureD.state = true;
                    FigureD();
                    figureD.menu += " <changed>";
                }
            }
            break;
        }
    } while ((figureA.state || figureBGlobal.state || figureC.state || figureD.state) == true);

}

int chekCircleValue(double Xdot, double Ydot, double Xc, double Yc, double r) {
    bool value;
    double check = pow(pow(Xdot - Xc, 2) - pow(Ydot - Yc, 2), 0.5);
    if (check < r) {
        value = true;
    }
    else {
        value = false;
    }
    return value;
}

int checkRecValue(double Xdot, double Ydot, double Xc, double Yc, double h, double w) {
    bool value = false;
    if (abs(Xdot - Xc) <= (w/2) && abs(Ydot - Yc) <= (h/2)) {
        value = true;
    }
    return value;
}

int main() {
    bool status = true;
    figureA.state = true;
    figureBGlobal.state = true;
    figureC.state = true;
    figureD.state = true;
    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Enter the figures" << endl << "2. See the results of figure buiding" << endl << "3. Check the dots" << endl << "4. Exit" << endl;
        int choice;
        cout << endl;
        cout << "Your choice - "; cin >> choice;
        switch (choice) {
        case 1:
            if (!figureA.state && !figureBGlobal.state && !figureC.state && !figureD.state) {
                int Restart;
                cout << endl;
                cout << "You already buildt the figures";
                cout << endl;
                cout << "Do you want to change it?";
                cout << endl;
                cout << "1. Yes" << endl << "2. No";
                cout << endl;
                cout << "Choose: "; cin >> Restart;
                switch (Restart)
                {
                case 1:
                     figureA.state = true;
                     figureBGlobal.state = true;
                     figureC.state = true;
                     figureD.state = true;
                    cout << endl;
                    EnterFiguresFunc();
                    cout << endl;
                break;
                case 2:
                
                break;
                }
            }
            else {
                cout << endl;
                EnterFiguresFunc();
                cout << endl;
            }
            break;
        case 2:
            if (!figureA.state && !figureBGlobal.state && !figureC.state && !figureD.state) {
                cout << endl;
                cout << "Figure result: " << endl;
                cout << "1. Figure A - " << figureA.figureType << ": the cords are "; cout << printArray(figureA.end, figureA.optionsArray);
                cout << endl;
                cout << "2. Figure B - " << figureBGlobal.figureType << ": the cords are "; if (checkFigureB == 0) { cout << printArray(figureBGlobal.end, figureBp.optionsArray); }else { cout << printArray(figureBGlobal.end, figureBn.optionsArray); }
                cout << endl;
                cout << "3. Figure C - " << figureC.figureType << ": the cords are "; cout << printArray(figureC.end, figureC.optionsArray);
                cout << endl;
                cout << "4. Figure D - " << figureD.figureType << ": the cords are "; cout << printArray(figureD.end, figureD.optionsArray);
                cout << endl;
            }
            else {
                cout << endl;
                cout << ERROR2;
                cout << endl;
            }
            break;
        case 3:
            double x, y;
            bool a, b, c, d;
            if (!figureA.state && !figureBGlobal.state && !figureC.state && !figureD.state) {
                cout << "Point the dot:" << endl;
                cout << "Cord x - "; cin >> x;
                cout << endl;
                cout << "Cord y - "; cin >> y;
                if (figureA.figureType == "Circle") {
                    A.circle = chekCircleValue(x, y, A.x0, A.y0, A.radius);
                    cout << "Figure A - " << outputRes(A.circle) << endl;
                    a = A.circle;
                }
                else {
                    A.rectangle = checkRecValue(x, y, A.x0, A.y0, A.hieght, A.weight);
                    cout << "Figure A - " << outputRes(A.rectangle) << endl;
                    a = A.rectangle;
                }
                if (figureBGlobal.figureType == "Circle") {
                    if (checkFigureB == 0) {Bg.circle = chekCircleValue(x, y, Bp.x0, Bp.y0, Bp.radius);} else {Bg.circle = chekCircleValue(x, y, Bn.x0, Bn.y0, Bn.radius);}
                    cout << "Figure B - " << outputRes(Bg.circle) << endl;
                    b = Bg.circle;
                }
                else {
                    if(checkFigureB == 0) {Bg.rectangle = checkRecValue(x, y, Bp.x0, Bp.y0, Bp.hieght, Bp.weight);} else {Bg.rectangle = checkRecValue(x, y, Bn.x0, Bn.y0, Bn.hieght, Bn.weight);}
                    cout << "Figure B - " << outputRes(Bg.rectangle) << endl;
                    b = Bg.rectangle;
                }
                if (figureC.figureType == "Circle") {
                    C.circle = chekCircleValue(x, y, C.x0, C.y0, A.radius);
                    cout << "Figure C - " << outputRes(C.circle) << endl;
                    c = C.circle;
                }
                else {
                    C.rectangle = checkRecValue(x, y, C.x0, C.y0, C.hieght, C.weight);
                    cout << "Figure C - " <<outputRes(C.rectangle) << endl;
                    c = C.rectangle;
                }
                if (figureD.figureType == "Circle") {
                    D.circle = chekCircleValue(x, y, D.x0, D.y0, A.radius);
                    cout << "Figure D - " << outputRes(D.circle) << endl;
                    d = D.circle;
                }
                else {
                    D.rectangle = checkRecValue(x, y, D.x0, D.y0, D.hieght, D.weight);
                    cout << "Figure D - " << outputRes(D.rectangle) << endl;
                    d = D.rectangle;
                }
                bool statement = (!(a && b) || d) || c;
                    cout << endl;
                    cout << "((!(a && b) || d) || c) - " << outputRes(statement);
                    cout << endl;
            }
            else {
                cout << endl;
                cout << ERROR2;
                cout << endl;
            }

            break;
        case 4:
            cout << "Programm finished!";
            cout << endl;
            status = false;
            break;
        default:
            cout << ERROR3 << endl;
            break;
        }
    } while (status);
}