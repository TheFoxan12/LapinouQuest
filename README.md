# Projet So_long<br>

## Presentation<br>
Ce projet représente la quête de Lapinou, qui doit récupérer toutes les carottes qu'il a égarées avant d'aller streamer.<br>
Déplacez Lapinou à l'aide des touches WASD, récupérez toutes les carottes et atteignez la sortie en effectuant le moins de mouvements possibles (il ne faudrait pas trop fatiguer Lapinou...)
<br><img src="assets/chars/face.png">
## Spécifications techniques<br>
### Le Jeu<br>
• Le but du joueur est de collecter tous les items présents sur la carte, puis de
s’échapper en empruntant le chemin le plus court possible.<br>
• Les touches W, A, S et D doivent être utilisées afin de mouvoir le personnage
principal.<br>
• Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas,
gauche, droite.<br>
• Le joueur ne doit pas pouvoir se déplacer dans les murs.<br>
• À chaque mouvement, le compte total de mouvement doit être affiché dans le
shell.<br>
• Vous devez utiliser une vue 2D (vue de haut ou de profil).<br>
• Le jeu n’a pas à être en temps réel.<br>
• Bien que les exemples donnés montrent un thème dauphin, vous êtes libre de créer
l’univers que vous voulez.<br>
### Gestion graphique<br>
• Votre programme doit afficher une image dans une fenêtre.<br>
• La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).<br>
• Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme proprement.<br>
• Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme
proprement.<br>
• Utiliser les images de la MiniLibX (ou MLX42) est obligatoire.<br>
<img src="assets/items/carrothighres.png">
### La carte<br>
• La carte sera construite en utilisant 3 éléments : les murs, les items à collecter,
et l’espace vide.<br>
• Votre carte peut être composée de ces 5 caractères :<br>
0 pour un emplacement vide,<br>
1 pour un mur,<br>
C pour un item à collecter (C pour collectible),<br>
E pour une sortie (E pour exit),<br>
P pour la position de départ du personnage.<br>
Exemple de carte basique :<br>
```     
        1111111111111
        10010000000C1
        1000011111001
        1P0011E000001
        1111111111111
```
• La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.<br>
Si la map contient des doublons, vous devez afficher un message d’erreur.<br>
• La carte doit être de forme rectangulaire.<br>
• La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
programme retourne une erreur.<br>
• Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)
dans la carte.<br>
• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
énoncées ci-dessus.<br>
• Un autre exemple de carte .ber basique :<br>
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
• Si une erreur de configuration est détectée, le programme doit quitter proprement
et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix<br>
[<img src="assets/world/finish.png">](http://twitch.tv/lapinoutv/)