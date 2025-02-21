#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_NAME_LENGTH 50

typedef struct Song {
    char name[MAX_SONG_NAME_LENGTH];
    struct Song *next;
} Song;

Song *createSong(const char *name) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    if (newSong == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newSong->name, name);
    newSong->next = NULL;
    return newSong;
}

void addSong(Song **head, const char *name) {
    Song *newSong = createSong(name);
    if (*head == NULL) {
        *head = newSong;
        newSong->next = *head; // Make it circular
        return;
    }

    Song *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->next = *head;
}

void playNextSong(Song **currentSong) {
    if (*currentSong == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    *currentSong = (*currentSong)->next;
    printf("Current Song: %s\n", (*currentSong)->name);
}

void displayCurrentSong(Song *currentSong) {
    if (currentSong == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Current Song: %s\n", currentSong->name);
}

void freePlaylist(Song *head) {
    if (head == NULL) return;

    Song *current = head;
    Song *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}


int main() {
    Song *playlist = NULL;
    Song *currentSong = NULL; // Keep track of the currently playing song

    addSong(&playlist, "Song A");
    if (currentSong == NULL) currentSong = playlist; //Set the first song as the current song
    addSong(&playlist, "Song B");
    addSong(&playlist, "Song C");

    displayCurrentSong(currentSong); // Current Song: Song A
    playNextSong(&currentSong);       // Current Song: Song B
    playNextSong(&currentSong);       // Current Song: Song C
    playNextSong(&currentSong);       // Current Song: Song A 
    playNextSong(&currentSong);       // Current Song: Song B
    playNextSong(&currentSong);       // Current Song: Song C

    freePlaylist(playlist); //Free the allocated memory to avoid memory leaks

    return 0;
}
