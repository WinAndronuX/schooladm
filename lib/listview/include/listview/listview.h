#ifndef LISTVIEW_H
#define LISTVIEW_H

#ifdef _WIN32
#define printSymbol(u, w) printf("%c", w)
#else
#define printSymbol(u, w) printf(u)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char* title;
    int* colsSizes;
    char** heads;
    int nCols;
    int iCols;
    int counter;
} ListView;

ListView* listviewCreate(const char* title, int nCols);
void listviewHeadAdd(ListView* lv, const char* text, int size);
void listviewHeadAddAuto(ListView* lv, const char* text);
void listviewAdd(ListView* lv, const char* text);
void listviewFootPrint(ListView* lv);

#ifdef __cplusplus
}
#endif

#endif
