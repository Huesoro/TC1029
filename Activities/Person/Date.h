//
//  Date.h
//  personTeacherInheritanceCompositionFiles
//
//  Created by Yolanda Martínez Treviño on 01/06/23.
//

#ifndef Date_h
#define Date_h

class Date {
public:
    Date();
    Date(int, int, int);
    int getDd() {return dd;}
    int getMm() {return mm;}
    int getYy() {return yy;}
    void setDd(int d) {dd = d;}
    void setMm(int m) {mm = m;}
    void setYy(int y) {yy = y;}
private:
    int dd;
    int mm;
    int yy;
};

Date :: Date(){
    dd = 1;
    mm = 1;
    yy = 1;
}

Date :: Date(int d, int m, int y) {
    dd = d;
    mm = m;
    yy = y;
}


#endif /* Date_h */
