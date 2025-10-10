#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === Fonction pour créer le négatif ===
void negatif_ppm(const char *fichier_source, const char *fichier_resultat) {
    FILE *src = fopen(fichier_source, "r");
    if (!src) {
        printf(" Erreur : impossible d'ouvrir %s\n", fichier_source);
        return;
    }

    char format[3];
    int largeur, hauteur, max;

    // Lecture de l’en-tête du fichier
    fscanf(src, "%2s", format);
    fscanf(src, "%d %d", &largeur, &hauteur);
    fscanf(src, "%d", &max);

    int total_pixels = largeur * hauteur;
    unsigned char *pixels = malloc(total_pixels * 3);
    if (!pixels) {
        printf(" Erreur d'allocation mémoire\n");
        fclose(src);
        return;
    }

    // Lecture des valeurs RGB
    for (int i = 0; i < total_pixels * 3; i++) {
        fscanf(src, "%hhu", &pixels[i]);
    }
    fclose(src);

    // Création du négatif
    for (int i = 0; i < total_pixels * 3; i++) {
        pixels[i] = (unsigned char)(max - pixels[i]);
    }

    // Écriture du résultat
    FILE *res = fopen(fichier_resultat, "w");
    if (!res) {
        printf(" Erreur : impossible de créer %s\n", fichier_resultat);
        free(pixels);
        return;
    }

    fprintf(res, "%s\n%d %d\n%d\n", format, largeur, hauteur, max);
    for (int i = 0; i < total_pixels * 3; i++) {
        fprintf(res, "%d ", pixels[i]);
    }

    fclose(res);
    free(pixels);
    printf(" Négatif créé avec succès dans %s\n", fichier_resultat);
}