#pragma once
#include "MapObject.hpp"
#include <allegro5/allegro.h>
#include <list>

class Player : public MapObject {
    public:
        Player(int start_x, int start_y, int number, bool team, const char* sprite_name);
        ~Player();

        void move();

        virtual void on_collision(MapObject &other);

        void set_dest(int dest_x, int dest_y);

        short get_number();
        
        int get_hit_points();
        void hit(const int amount); // Reduce hp by amount without overflow
        void die(); // Will probably respawn the player, awatining decisions

        bool get_team();

        void draw(int camera_x, int camera_y);

    private:
        short number;
        int speed = 15;
        int old_x;
        int old_y;
        int dest_x;
        int dest_y;
        int hit_points;
        int lastgoodposx;
        int lastgoodposy;
        bool team;
        ALLEGRO_BITMAP* sprite;
};
