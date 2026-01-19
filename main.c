#include <gtk/gtk.h>

static void button_clicked (GtkButton *button, gpointer user_data) {
  GtkWidget *label = user_data;
  gtk_label_set_text(GTK_LABEL(label), "Button Clicked");
}

static void activate (GtkApplication* app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *box;
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Hello Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 100);
  label = gtk_label_new("GTK4 Programming in C");
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_window_set_child (GTK_WINDOW (window), box);
  button = gtk_button_new_with_label ("Click Me");
  gtk_button_set_has_frame(GTK_BUTTON(button), FALSE);
  g_signal_connect (GTK_BUTTON (button), "clicked", G_CALLBACK (button_clicked), label);
  gtk_box_append(GTK_BOX(box), label);
  gtk_box_append(GTK_BOX(box), button);
  gtk_window_present(GTK_WINDOW(window));
}

int main (int argc, char **argv) {
  GtkApplication *app;
  int status;
  app = gtk_application_new ("org.gtk.demo", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return status;
}
