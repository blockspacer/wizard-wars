#pragma once
#include "Map.hpp"
#include "MapObject.hpp"
#include "Spells.hpp"

class Beam: public Spell {
    public:
        Beam(int start_x, int start_y, float dir_x, float dir_y, int width, int height, bool noclip, Map* &map);
        ~Beam();

        void move();

        virtual void draw(int camera_x, int camera_y);
    
    protected:
        int range;
        int lifetime;
        int originx;
        int originy;
        //bool hitted;
};