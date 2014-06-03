#include <pebble.h>

static Window *window;
static Window *windowBal;
static Window *windowPayContacts;
static Window *windowPayAmount;
static Window *windowPayConfirm;
static Window *windowRequestContacts;
static Window *windowRequestAmount;
static Window *windowRequestConfirm;
static Window *windowFeed;

static TextLayer *text_layer;

MenuLayer *menu_layer;
MenuLayer *menu_layer_PayContacts;
MenuLayer *menu_layer_PayAmount;
MenuLayer *menu_layer_PayConfirm;

MenuLayer *menu_layer_RequestContacts;
MenuLayer *menu_layer_RequestAmount;
MenuLayer *menu_layer_RequestConfirm;
MenuLayer *menu_layer_Feed;

void windowRequestContacts_unload(Window *windowRequestContacts);
  void windowRequestContacts_load(Window *windowRequestContacts);

void windowRequestAmount_unload(Window *windowRequestAmount);
  void windowRequestAmount_load(Window *windowRequestAmount);

void windowRequestConfirm_unload(Window *windowRequestConfirm);
  void windowRequestConfirm_load(Window *windowRequestConfirm);


void windowPayContacts_unload(Window *windowPayContacts);
  void windowPayContacts_load(Window *windowPayContacts);

void windowPayAmount_unload(Window *windowPayAmount);
  void windowPayAmount_load(Window *windowPayAmount);

void windowPayConfirm_unload(Window *windowPayConfirm);
  void windowPayConfirm_load(Window *windowPayConfirm);


void windowFeed_unload(Window *windowFeed);
  void windowFeed_load(Window *windowFeed);


static char buffer[20]="";
static char bu1[120]="";
static char cont1[20]="";
static char cont2[20]="";
static char cont3[20]="";
static char cont4[20]="";
static char cont5[20]="";
static char feed[120]="";
static char feed1[20]="";
static char feed2[20]="";
static char feed3[20]="";
static char feed4[20]="";
static char feed5[20]="";


// Key values for AppMessage Dictionary
enum {
    MESSAGE_KEY = 0,
      contact=1,
        feedd=2
     
};


void windowBal_unload(Window *windowBal)
{
  
    text_layer_destroy(text_layer);
    window_destroy(windowBal);
}


void windowBal_load(Window *windowBal)
{
  APP_LOG(APP_LOG_LEVEL_DEBUG, "WindowBalanceload");

    Layer *windowBal_layer = window_get_root_layer(windowBal);
    GRect bounds = layer_get_bounds(windowBal_layer);  
 APP_LOG(APP_LOG_LEVEL_DEBUG, "Ready1");

  text_layer = text_layer_create((GRect) { .origin = { 0, 50 }, .size = { bounds.size.w, 60 } });
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD));
  text_layer_set_text_color(text_layer, GColorWhite);
  text_layer_set_background_color(text_layer, GColorBlack);
 APP_LOG(APP_LOG_LEVEL_DEBUG, "Ready2");
  text_layer_set_text(text_layer, buffer);                     
   APP_LOG(APP_LOG_LEVEL_DEBUG, "Ready4");

  layer_add_child(windowBal_layer, text_layer_get_layer(text_layer));
  
}



















uint16_t num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 4;
}

uint16_t num_rows_callback_PayContacts(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 5;
}

uint16_t num_rows_callback_PayAmount(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 10;
}

uint16_t num_rows_callback_PayConfirm(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 2;
}












void draw_row_callback(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "Check Balance", "Check your account balance " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, "Pay", "Pay Someone Money", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, "Request", "Request Money", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, "Feed", "Your recent transactions", NULL);
        break;
    }
}



void draw_row_callback_PayContacts(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, cont1, "Check your account balance " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, cont2, "Pay Someone Money", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, cont3, "Request Money", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, cont4, "Your recent transactions", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, cont5, "Your recent transactions", NULL);
        break;
    }
}

void draw_row_callback_PayAmount(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "$1", "Check your account balance " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, "$2", "Pay Someone Money", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, "$5", "Request Money", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, "$10", "Your recent transactions", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, "$20", "Your recent transactions", NULL);
        break;
    case 5:
        menu_cell_basic_draw(ctx, cell_layer, "$50", "Check your account balance " , NULL);
        break;
    case 6:
        menu_cell_basic_draw(ctx, cell_layer, "$100", "Pay Someone Money", NULL);
        break;
    case 7:
        menu_cell_basic_draw(ctx, cell_layer, "$200", "Request Money", NULL);
        break;
    case 8:
        menu_cell_basic_draw(ctx, cell_layer, "$500", "Your recent transactions", NULL);
        break;
    case 9:
        menu_cell_basic_draw(ctx, cell_layer, "$1000", "Your recent transactions", NULL);
        break;
    case 10:
        menu_cell_basic_draw(ctx, cell_layer, "$2000", "Check your account balance " , NULL);
        break;
    }
}

void draw_row_callback_PayConfirm(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "Press SELECT", "To Confirm " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, " Press BACK", "To go Back", NULL);
        break;
    }
}






















void select_click_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Click");
    int which = cell_index->row;
    if(which==0)
    {
      
    windowBal = window_create();
    window_set_background_color(windowBal, GColorWhite);
  
      window_set_window_handlers(windowBal, (WindowHandlers) {
	    .load = windowBal_load,
      .unload = windowBal_unload,
  });
    
      
      window_stack_push(windowBal, true); 

    }
  
  
  else if(which==1)
  {
    
    
     windowPayContacts = window_create();
    window_set_background_color(windowPayContacts, GColorWhite);
  
      window_set_window_handlers(windowPayContacts, (WindowHandlers) {
	    .load = windowPayContacts_load,
      .unload = windowPayContacts_unload,
  });
    
      
      window_stack_push(windowPayContacts, true); 
    
    
  }
   else if(which==2)
  {
    
    
     windowRequestContacts = window_create();
    window_set_background_color(windowRequestContacts, GColorWhite);
  
      window_set_window_handlers(windowRequestContacts, (WindowHandlers) {
	    .load = windowRequestContacts_load,
      .unload = windowRequestContacts_unload,
  });
    
      
      window_stack_push(windowRequestContacts, true); 
    
    
  }
  
   else if(which==3)
  {
    
    
     windowFeed = window_create();
    window_set_background_color(windowFeed, GColorWhite);
  
      window_set_window_handlers(windowFeed, (WindowHandlers) {
	    .load = windowFeed_load,
      .unload = windowFeed_unload,
  });
    
      
      window_stack_push(windowFeed, true); 
    
    
  }
  
  
	  
}




void select_click_callback_PayContacts(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Click");
    int which = cell_index->row;
    if(which==0)
    {
      
    windowPayAmount = window_create();
    window_set_background_color(windowPayAmount, GColorWhite);
  
      window_set_window_handlers(windowPayAmount, (WindowHandlers) {
	    .load = windowPayAmount_load,
      .unload = windowPayAmount_unload,
  });
    
      
      window_stack_push(windowPayAmount, true); 

    }
  
	  
}

void select_click_callback_PayAmount(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "ClickClaack");
    int which = cell_index->row;
    if(which==0)
    {
      
    windowPayConfirm = window_create();
    window_set_background_color(windowPayConfirm, GColorWhite);
  
      window_set_window_handlers(windowPayConfirm, (WindowHandlers) {
	    .load = windowPayConfirm_load,
      .unload = windowPayConfirm_unload,
  });
    
      
      window_stack_push(windowPayConfirm, true); 

    }
  
	  
}



void select_click_callback_PayConfirm(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  DictionaryIterator *iter;
	app_message_outbox_begin(&iter);
	Tuplet backpay = TupletCString(999,"backpay" );
	dict_write_tuplet(iter, &backpay);
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Click");
  window_stack_pop(true);
  window_stack_pop(true);
  window_stack_pop(true);
  
}













void windowPayContacts_unload(Window *windowPayContacts)
{
  
    menu_layer_destroy(menu_layer_PayContacts);
    window_destroy(windowPayContacts);
}

void windowPayContacts_load(Window *windowPayContacts)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Contacts");

    Layer *windowPayContacts_layer = window_get_root_layer(windowPayContacts);
    GRect bounds = layer_get_bounds(windowPayContacts_layer);

    menu_layer_PayContacts = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_PayContacts,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_PayContacts,
        .select_click = (MenuLayerSelectCallback) select_click_callback_PayContacts
    };
    menu_layer_set_callbacks(menu_layer_PayContacts, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_PayContacts, windowPayContacts);
 
  layer_add_child(window_get_root_layer(windowPayContacts), menu_layer_get_layer(menu_layer_PayContacts));
  
}







void windowPayAmount_unload(Window *windowPayAmount)
{
  
    menu_layer_destroy(menu_layer_PayAmount);
    window_destroy(windowPayAmount);
}

void windowPayAmount_load(Window *windowPayAmount)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Con");

    Layer *windowPayAmount_layer = window_get_root_layer(windowPayAmount);
    GRect bounds = layer_get_bounds(windowPayAmount_layer);

    menu_layer_PayAmount = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_PayAmount,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_PayAmount,
        .select_click = (MenuLayerSelectCallback) select_click_callback_PayAmount
    };
    menu_layer_set_callbacks(menu_layer_PayAmount, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_PayAmount, windowPayAmount);
 
  layer_add_child(window_get_root_layer(windowPayAmount), menu_layer_get_layer(menu_layer_PayAmount));
  
}



void windowPayConfirm_unload(Window *windowPayConfirm)
{
  
    menu_layer_destroy(menu_layer_PayConfirm);
    window_destroy(windowPayConfirm);
}

void windowPayConfirm_load(Window *windowPayConfirm)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Conaaaa");

    Layer *windowPayConfirm_layer = window_get_root_layer(windowPayConfirm);
    GRect bounds = layer_get_bounds(windowPayConfirm_layer);

    menu_layer_PayConfirm = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_PayConfirm,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_PayConfirm,
        .select_click = (MenuLayerSelectCallback) select_click_callback_PayConfirm
    };
    menu_layer_set_callbacks(menu_layer_PayConfirm, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_PayConfirm, windowPayConfirm);
 
  layer_add_child(window_get_root_layer(windowPayConfirm), menu_layer_get_layer(menu_layer_PayConfirm));
  
}





















uint16_t num_rows_callback_RequestContacts(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 5;
}

uint16_t num_rows_callback_RequestAmount(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 10;
}

uint16_t num_rows_callback_RequestConfirm(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 2;
}









void draw_row_callback_RequestContacts(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, cont1, "Check your account balance " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, cont2, "Request Someone Money", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, cont3, "Request Money", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, cont4, "Your recent transactions", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, cont5, "Your recent transactions", NULL);
        break;
    }
}

void draw_row_callback_RequestAmount(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "$1", "Check your account balance " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, "$2", "Request Someone Money", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, "$5", "Request Money", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, "$10", "Your recent transactions", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, "$20", "Your recent transactions", NULL);
        break;
    case 5:
        menu_cell_basic_draw(ctx, cell_layer, "$50", "Check your account balance " , NULL);
        break;
    case 6:
        menu_cell_basic_draw(ctx, cell_layer, "$100", "Request Someone Money", NULL);
        break;
    case 7:
        menu_cell_basic_draw(ctx, cell_layer, "$200", "Request Money", NULL);
        break;
    case 8:
        menu_cell_basic_draw(ctx, cell_layer, "$500", "Your recent transactions", NULL);
        break;
    case 9:
        menu_cell_basic_draw(ctx, cell_layer, "$1000", "Your recent transactions", NULL);
        break;
    case 10:
        menu_cell_basic_draw(ctx, cell_layer, "$2000", "Check your account balance " , NULL);
        break;
    }
}

void draw_row_callback_RequestConfirm(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "Press SELECT", "To Confirm " , NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, " Press BACK", "To go Back", NULL);
        break;
    }
}
























void select_click_callback_RequestContacts(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Click");
    int which = cell_index->row;
    if(which==0)
    {
      
    windowRequestAmount = window_create();
    window_set_background_color(windowRequestAmount, GColorWhite);
  
      window_set_window_handlers(windowRequestAmount, (WindowHandlers) {
      .load = windowRequestAmount_load,
      .unload = windowRequestAmount_unload,
  });
    
      
      window_stack_push(windowRequestAmount, true); 

    }
  
    
}

void select_click_callback_RequestAmount(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "ClickClaack");
    int which = cell_index->row;
    if(which==0)
    {
      
    windowRequestConfirm = window_create();
    window_set_background_color(windowRequestConfirm, GColorWhite);
  
      window_set_window_handlers(windowRequestConfirm, (WindowHandlers) {
      .load = windowRequestConfirm_load,
      .unload = windowRequestConfirm_unload,
  });
    
      
      window_stack_push(windowRequestConfirm, true); 

    }
  
    
}



void select_click_callback_RequestConfirm(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Click");
  window_stack_pop(true);
  window_stack_pop(true);
  window_stack_pop(true);
  
}













void windowRequestContacts_unload(Window *windowRequestContacts)
{
  
    menu_layer_destroy(menu_layer_RequestContacts);
    window_destroy(windowRequestContacts);
}

void windowRequestContacts_load(Window *windowRequestContacts)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Contacts");

    Layer *windowRequestContacts_layer = window_get_root_layer(windowRequestContacts);
    GRect bounds = layer_get_bounds(windowRequestContacts_layer);

    menu_layer_RequestContacts = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_RequestContacts,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_RequestContacts,
        .select_click = (MenuLayerSelectCallback) select_click_callback_RequestContacts
    };
    menu_layer_set_callbacks(menu_layer_RequestContacts, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_RequestContacts, windowRequestContacts);
 
  layer_add_child(window_get_root_layer(windowRequestContacts), menu_layer_get_layer(menu_layer_RequestContacts));
  
}







void windowRequestAmount_unload(Window *windowRequestAmount)
{
  
    menu_layer_destroy(menu_layer_RequestAmount);
    window_destroy(windowRequestAmount);
}

void windowRequestAmount_load(Window *windowRequestAmount)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Con");

    Layer *windowRequestAmount_layer = window_get_root_layer(windowRequestAmount);
    GRect bounds = layer_get_bounds(windowRequestAmount_layer);

    menu_layer_RequestAmount = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_RequestAmount,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_RequestAmount,
        .select_click = (MenuLayerSelectCallback) select_click_callback_RequestAmount
    };
    menu_layer_set_callbacks(menu_layer_RequestAmount, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_RequestAmount, windowRequestAmount);
 
  layer_add_child(window_get_root_layer(windowRequestAmount), menu_layer_get_layer(menu_layer_RequestAmount));
  
}




void windowRequestConfirm_unload(Window *windowRequestConfirm)
{
  
    menu_layer_destroy(menu_layer_RequestConfirm);
    window_destroy(windowRequestConfirm);
}

void windowRequestConfirm_load(Window *windowRequestConfirm)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Conaaaa");

    Layer *windowRequestConfirm_layer = window_get_root_layer(windowRequestConfirm);
    GRect bounds = layer_get_bounds(windowRequestConfirm_layer);

    menu_layer_RequestConfirm = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_RequestConfirm,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_RequestConfirm,
        .select_click = (MenuLayerSelectCallback) select_click_callback_RequestConfirm
    };
    menu_layer_set_callbacks(menu_layer_RequestConfirm, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_RequestConfirm, windowRequestConfirm);
 
  layer_add_child(window_get_root_layer(windowRequestConfirm), menu_layer_get_layer(menu_layer_RequestConfirm));
  
}






uint16_t num_rows_callback_Feed(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
 return 5;
}



void draw_row_callback_Feed(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
  
  switch(cell_index->row)
    {
    case 0:
  
        menu_cell_basic_draw(ctx, cell_layer, feed1, " " , NULL);
          break;
    case 1:
          menu_cell_basic_draw(ctx, cell_layer, feed2, " ", NULL);
        break;
    case 2:
          menu_cell_basic_draw(ctx, cell_layer, feed3, " ", NULL);
        break;
    case 3:
          menu_cell_basic_draw(ctx, cell_layer, feed4, " ", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, feed5, " ", NULL);
        break;
    }
}






void windowFeed_unload(Window *windowFeed)
{
  
    menu_layer_destroy(menu_layer_Feed);
    window_destroy(windowFeed);
}

void windowFeed_load(Window *windowFeed)
{APP_LOG(APP_LOG_LEVEL_DEBUG, "Conaaaaasdasd");

    Layer *windowFeed_layer = window_get_root_layer(windowFeed);
    GRect bounds = layer_get_bounds(windowFeed_layer);

    menu_layer_Feed = menu_layer_create(GRect(0, 0, 144, 168 - 16));
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback_Feed,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback_Feed,
            };
    menu_layer_set_callbacks(menu_layer_Feed, NULL, callbacks);
 
 menu_layer_set_click_config_onto_window(menu_layer_Feed, windowFeed);
 
  layer_add_child(window_get_root_layer(windowFeed), menu_layer_get_layer(menu_layer_Feed));
  
}






























// Called when a message is received from PebbleKitJS
static void in_received_handler(DictionaryIterator *received, void *context) {
    Tuple *balance,*contacter,*feeder;
  
    balance = dict_find(received, MESSAGE_KEY);
 
    if(balance) {
       // APP_LOG(APP_LOG_LEVEL_DEBUG, "Received Message: %s", tuple->value->cstring);
      strncpy(buffer, balance->value->cstring, sizeof(buffer));
    
    }
   
  
  contacter = dict_find(received, contact);
   if(contacter)
  {
    int m=-1,j=0; 
     strncpy(bu1, contacter->value->cstring, sizeof(bu1));
     for(unsigned int i=0;i<sizeof(bu1);i++)
       
     {
       if(bu1[i]!='|'){
     if(m==0)
       cont1[j++]=bu1[i];
     else if(m==1)
       cont2[j++]=bu1[i];
     else if(m==2)
       cont3[j++]=bu1[i];
          else if(m==3)
       cont4[j++]=bu1[i];
          else if(m==4)
       cont5[j++]=bu1[i];
       }
       
       
       else
       {
         m++;
         j=0;
       }
        
   }
   }
  feeder = dict_find(received,feedd);
  if(feeder)
  { int m=-1,j=0;
   
    strncpy(feed,feeder->value->cstring, sizeof(feed));
   
     for(unsigned int i=0;i<sizeof(feed);i++)
       
     {
       if(feed[i]!='|'){
     if(m==0)
       feed1[j++]=feed[i];
     else if(m==1)
       feed2[j++]=feed[i];
     else if(m==2)
       feed3[j++]=feed[i];
          else if(m==3)
       feed4[j++]=feed[i];
          else if(m==4)
       feed5[j++]=feed[i];
       }
       
       
       else
       {
         m++;
         j=0;
       }
        
   }
    
  }
    
}








void init(void) {
    window = window_create();
    window_set_background_color(window, GColorWhite);
    window_stack_push(window, true);

    // Register AppMessage handlers
    app_message_register_inbox_received(in_received_handler); 
    app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());

    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_bounds(window_layer);
  
  menu_layer = menu_layer_create(GRect(0, 0, 144, 168 - 16));
   
  MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback,
        .select_click = (MenuLayerSelectCallback) select_click_callback
    };
    menu_layer_set_callbacks(menu_layer, NULL, callbacks);
 
    menu_layer_set_click_config_onto_window(menu_layer, window);
    layer_add_child(window_get_root_layer(window), menu_layer_get_layer(menu_layer));
  }

void deinit(void) {
    app_message_deregister_callbacks();
    text_layer_destroy(text_layer);
    window_destroy(window);
}

int main( void ) {
    init();
    app_event_loop();
    deinit();
}