#include "gui.h"
#include <gtk/gtk.h>



/* Another callback */
static void quit( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}

static void send( GtkWidget *widget,
                   gpointer   data )
{
    g_print (" sending mail to be done \n");
}

void giveMeACall(void (*callback)() ){
  g_print (" calling callback from c \n");
  
  if(callback){
    (*callback)();
  }else{
    g_print ("amit has skrewed up something callback null \n");
  }
}

void showGtkUI(int argc, char* argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *toLabel, *fromLabel , *bodyLabel;
    GtkWidget *toEntry, * fromEntry, *bodyEntry;
    GtkWidget *box;


    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    g_signal_connect (window, "destroy", G_CALLBACK (quit), NULL);
    
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    box = gtk_vbox_new (FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show(box);

    // Create a label and add it to the box
    toLabel = gtk_label_new ("enter recipient");
    gtk_box_pack_start (GTK_BOX (box), toLabel, TRUE, TRUE, 5);
    gtk_widget_show(toLabel);


    // Create an entry field and add it to the box
    toEntry = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (box), toEntry, TRUE, TRUE, 5);
    gtk_widget_show(toEntry);
    gtk_widget_grab_focus(toEntry);


//-----------------------------------------------------------------

    // Create a label and add it to the box
    fromLabel = gtk_label_new ("enter sender ");
    gtk_box_pack_start (GTK_BOX (box), fromLabel, TRUE, TRUE, 5);
    gtk_widget_show(fromLabel);


    // Create an entry field and add it to the box
    fromEntry = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (box), fromEntry, TRUE, TRUE, 5);
    gtk_widget_show(fromEntry);

    // Create a label and add it to the box
    bodyLabel = gtk_label_new ("enter message ");
    gtk_box_pack_start (GTK_BOX (box), bodyLabel, TRUE, TRUE, 5);
    gtk_widget_show(bodyLabel);

    // Create an entry field and add it to the box
    bodyEntry = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (box), bodyEntry, TRUE, TRUE, 5);
    gtk_widget_show(bodyEntry);


 /* Creates a new button with the label "Hello World". */
    button = gtk_button_new_with_label ("Sendmail");
    gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 5);
    g_signal_connect (button, "clicked",G_CALLBACK (send), NULL);

    
    /* This packs the button into the window (a gtk container). */
    gtk_container_add (GTK_CONTAINER (window), button);
    
    /* The final step is to display this newly created widget. */
    gtk_widget_show (button);

    gtk_widget_show  (window);
    
    gtk_main ();

}