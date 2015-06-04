/******************************************************************

                [Insira o nome do Jogo Aqui]
                            por
                Sophia Klein e Sidarta Correa

******************************************************************/

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int width = 1024;
const int height = 480;

struct Notas
{
    int cx;
    int cy;
    int raio;

}nota;

int main(void)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

	bool quit = false;
	bool redraw = true;


	//INICIALIZAÇÕES
	if(!al_init())
		return -1;

	display = al_create_display(width, height);
	if(!display)
		return -1;

    timer = al_create_timer(1.0/60);
    if(!timer)
        return -1;

    event_queue = al_create_event_queue();
    if(!event_queue)
        return -1;

	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	 //LISTA DOS POSSIVEIS EVENTOS
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //PREPARA
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    al_hide_mouse_cursor(display);
    while(!quit){

        ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            nota.cx = ev.mouse.x;
            nota.cy = ev.mouse.y;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {

        }

	    if(redraw){

        ALLEGRO_COLOR color_bg1 = al_map_rgb(100,149,227);
        ALLEGRO_COLOR color_bg2 = al_map_rgb(138,174,234);
        ALLEGRO_COLOR color_black = al_map_rgb(0,0,0);

        al_clear_to_color(color_bg2);
        al_draw_filled_rectangle(10,10,width-10,height-10,color_bg2);
        al_draw_line(15, height/2, width-15, height/2, color_black, 4);
        al_draw_line(15, height/2 - 28, width-15, height/2 - 28, color_black, 4);
        al_draw_line(15, height/2 - 56, width-15, height/2 - 56, color_black, 4);
        al_draw_line(15, height/2 + 28, width-15, height/2 + 28, color_black, 4);
        al_draw_line(15, height/2 + 56, width-15, height/2 + 56, color_black, 4);
        al_draw_circle(nota.cx, nota.cy, 14, color_black, 4);

        al_flip_display();

	    } //if gráfico
    } //while da porra toda

    al_destroy_display(display); //destroy our display object

	return 0;
}
