#ifndef __COORD_H__
#define __COORD_H__

class Coord {
    private:
        float x;
        float y;
    public: 
        Coord();
        Coord(float x, float y);
        float norm() const;

        bool operator==(const Coord &c) const ;
        Coord operator+(const Coord &c) const ;
        Coord operator-(const Coord &c) const ;
        Coord& operator+=(const Coord &c);

        Coord& operator-=(const Coord &c);

        Coord operator*(const float &f) const ;
        Coord operator/(const float &f) const;
        Coord& operator*=(const float &f);
        Coord& operator/=(const float &f);
        float & operator[](int dim);
        float operator[](int dim) const;


};

#endif // __COORD_H__