#include "../headers/Ice.hpp"
#include <iostream>
#include <math.h>
Ice::Ice(int start_x, int start_y, float dir_x, float dir_y) 
            : Projectile::Projectile(start_x, start_y, dir_x, dir_y, 12, 12, false, 40) {
    damage = 5;
    sprite = al_load_bitmap("resources/iceProjectiles.bmp");
}

int Ice::get_damage() {
    return damage;
}

void Ice::draw(int camera_x, int camera_y) {
    float at = atan2(dir_y,dir_x)*180.0/ALLEGRO_PI;
    al_draw_rotated_bitmap(this->sprite,0,0, x - camera_x, y - camera_y, at,0);
    //al_draw_bitmap(this->sprite, x - camera_x, y - camera_y, 0);
}

void Ice::on_collision(MapObject other) { }
