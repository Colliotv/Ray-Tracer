#!/usr/bin/python                                                               
import sys

def sphere(fichier):
    fichier.write("<object type = \"sphere\">\n")
    x = raw_input("Entrez les coordonnees de la sphere\nPour x : ")
    y = raw_input("Pour y : ")
    z = raw_input("pour z : ")
    position = "<position x=\"" + str(x) + "\" y =\"" + str(y) + "\" z=\"" + str(z) + "\" />\n"
    fichier.write(position)
    ray = raw_input("Entrez le rayon de la sphere : ")
    rayon = "<rayon R=\"" + str(ray) + "\"/>\n"
    fichier.write(rayon)
    r = raw_input("Entrez la couleur de la sphere\nPour r : ")
    g = raw_input("Pour g : ")
    b = raw_input("pour b : ")
    color = "<color r=\"" + str(r) + "\" g =\"" + str(g) + "\" b=\"" + str(b) + "\" />\n"
    fichier.write(color)
    fichier.write("</object>\n")
    
def eye(fichier):
    x = raw_input("Entrez les coordonnees de l'oeil\nPour x : ")
    y = raw_input("Pour y : ")
    z = raw_input("pour z : ")
    fichier.write("<eye>\n")
    position = "<position x=\"" + str(x) + "\" y =\"" + str(y) + "\" z=\"" + str(z) + "\" />\n"
    fichier.write(position)
    answer = raw_input("Souhaitez vous appliquer une rotation a l'oeil?(yes | no)")
    if (answer == "yes"):
        x = raw_input("Entrez les coordonnees rotation de l'oeil\nPour x : ")
        y = raw_input("Pour y : ")
        z = raw_input("pour z : ")
        direction = "<direction x=\"" + str(x) + "\" y =\"" + str(y) + "\" z=\"" + str(z) + "\" />\n"
        fichier.write(direction)
    else:
        fichier.write("<direction x=\"0.0\" y=\"0.0\" z=\"0.0\" />\n")
    fichier.write("</eye>\n")
  
def objet(fichier):
    type_objet = raw_input("Quel type d'objet souhaitez vous ? : ")
    if (type_objet == "sphere"):
        sphere(fichier)
    else:
        print("Cet objet n'existe pas\n")

def generator():
    name = raw_input("Entrez le nom de votre fichier : ")
    fichier = open(name, "w")
    fichier.write("<scene>\n")
    eye(fichier)
    nb_object = input("Combien d'objets souhaitez vous ? : ")
    objet(fichier)
    fichier.write("</scene>\n")

if __name__ == "__main__":
    generator()
