#ifndef G2_H
#define G2_H

extern unsigned int G2_COLOR;
extern unsigned int G2_ALPHA;

void g2_init();
void g2_uninit();

void g2_clear();
void g2_color(int red, int green, int blue);
void g2_alpha(int alpha);

void g2_rect(unsigned int flags, int left, int top, int width, int height);

void g2_text(int left, int top, char* text, int size);

#endif
