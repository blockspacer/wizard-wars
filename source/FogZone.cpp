#include "../headers/FogZone.hpp"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <math.h>
FogZ::FogZ(int start_x, int start_y) 
            : Zone::Zone(start_x, start_y, 400, 400, true) {
    damage = 0;
    sprite = al_load_bitmap("resources/fogZone.bmp");
    time = 0;
    element="1";
    music04 = al_load_sample("resources/fog_zone.wav");
    al_play_sample(music04, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0); //(SAMPLE NAME, gain(volumn), pan(balance), speed, play_mode, sample_id)
}

FogZ::FogZ(int start_x, int start_y, int ID, bool transmitted[5]) 
            : Zone::Zone(start_x, start_y, 400, 400, true) {
    damage = 0;
    sprite = al_load_bitmap("resources/fogZone.bmp");
    time = 0;
    element="1";
    id=ID;
    for(int i=0; i<5; i++){        
        this->transmitted[i]=transmitted[i];
    }
    music04 = al_load_sample("resources/fog_zone.wav");
    al_play_sample(music04, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0); //(SAMPLE NAME, gain(volumn), pan(balance), speed, play_mode, sample_id)
}

FogZ::~FogZ() {
    al_destroy_sample(music04);
    al_destroy_bitmap(sprite);
}
int FogZ::get_damage() {
    return damage;
}

// void must_init(bool, const char);

void FogZ::draw(int camera_x, int camera_y) {
    al_draw_scaled_bitmap(this->sprite, 0,0,64,64,x - camera_x, y - camera_y,width,height, 0);
    //how to count ticks?
    time=time+1;
    if (time>100) {
        this->garbage_collect = true;

    // must_init(al_init_primitives_addon(), "primitives");
    // must_init(al_init_image_addon(), "Image addon");
    // must_init(al_install_audio(), "Audio addon");
    // must_init(al_init_acodec_addon(), "Audio codecs addon");
    // must_init(al_reserve_samples(16), "reserve samples");
    //ALLEGRO_SAMPLE* music04 = al_load_sample("resources/fog_zone.wav");
    //al_play_sample(music04, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0); //(SAMPLE NAME, gain(volumn), pan(balance), speed, play_mode, sample_id)
    // ALLEGRO_FONT *font = al_load_bitmap_font("a4_font.tga");
    // al_draw_text(font, al_map_rgb(255, 255, 255), 300, 200, ALLEGRO_ALIGN_CENTRE, "Dzooooone");
    //al_destroy_sample(music04);
    }
    //al_draw_bitmap(this->sprite, x - camera_x, y - camera_y, 0);
   
}

void FogZ::on_collision(MapObject &other) {
    if (!this->get_garbage_collect() && !this->hit_animation) {
        other.hit(this->get_damage());
       // other.get_drawsprite()=false;
    }
 }