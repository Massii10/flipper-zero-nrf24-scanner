#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <nrf24/nrf24.h>

// Stato dell'applicazione
typedef struct {
    bool scanning;
    bool jamming;
    char selected_network[32];
} AppState;

// Funzione per disegnare il menu
void render_callback(Canvas* canvas, void* ctx) {
    AppState* app_state = ctx;
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 10, "NRF24 Scanner");

    if(app_state->scanning) {
        canvas_draw_str(canvas, 10, 30, "Scanning...");
    } else {
        canvas_draw_str(canvas, 10, 30, "Press center to scan");
    }

    if(app_state->selected_network[0] != '\0') {
        canvas_draw_str(canvas, 10, 50, "Selected Network:");
        canvas_draw_str(canvas, 10, 70, app_state->selected_network);
        canvas_draw_str(canvas, 10, 90, app_state->jamming ? "Jamming..." : "Press right to jam");
    }
}

// Funzione di gestione degli input
void input_callback(InputEvent* input_event, void* ctx) {
    AppState* app_state = ctx;
    if(input_event->type == InputTypePress) {
        if(input_event->key == InputKeyOk) {
            app_state->scanning = !app_state->scanning;
            if(app_state->scanning) {
                // Avvia la scansione
                nrf24_start_scan();
            } else {
                // Ferma la scansione
                nrf24_stop_scan();
            }
        } else if(input_event->key == InputKeyRight && app_state->selected_network[0] != '\0') {
            app_state->jamming = !app_state->jamming;
            if(app_state->jamming) {
                // Avvia il jammer
                nrf24_start_jam(app_state->selected_network);
            } else {
                // Ferma il jammer
                nrf24_stop_jam();
            }
        }
    }
}

// Funzione principale dell'applicazione
int32_t flipper_zero_app(void* p) {
    AppState app_state = {
        .scanning = false,
        .jamming = false,
        .selected_network = "",
    };

    // Inizializza GUI
    Gui* gui = furi_record_open("gui");
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, &app_state);
    view_port_input_callback_set(view_port, input_callback, &app_state);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    // Loop principale
    while(1) {
        furi_delay_ms(100);
    }

    // Libera le risorse
    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close("gui");

    return 0;
}