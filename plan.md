# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    plan.md                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 17:03:27 by llion             #+#    #+#              #
#    Updated: 2023/04/12 12:29:48 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PLAN DE BATAILLE

## MISC
- Un philosophe prend la fourchette a sa gauche et a sa droite 
- Apres manger un philosophe dort
- il pense a son reveil


parametres :
    - time_to_die : temps restant avant la mort
    - time_to_eat : temps que le philosophe prend pour manger
    - time_to_sleep : temps passe a dormir

- les philosophes sont assis cote a cote et numerotes dans l'ordre
- proteger les fouchette pour ne pas les dupliquer
- il faudra utiliser des mutex pour que les philosophes prennent les fourchettes a cote d'eux
- les semaphores peuvent serive a  checker quun nombre maximum de philos mangent ou pensent par exemple

- semaphores
	- sem_t sem
	- sem_init(&sem, 0(single or multiple proccesses, 1(init value -> nombre d'incr/decre possibles))
	- sem_destroy(&sem)
	- sem_wait(&sem) && sem_post(&sem) permet de faire comme les mutex

## A FAIRE


### definir les differentes structures

- philosophe
	- id
	- id des fourchettes gauche droite
	- etat
	- nombre de fois qu'il a mange
- table
	- nombre de philosophes assis
	- tableau des philosophes
	- tableau des fouchettes
- fouchette
	- id
	- etat (occupe ou non)
- parametres
	- temps max de simulation
	- nombre de philosophes a creer
	- temps min de sommeil
	- temps max de sommeil
	- Le nombre de fois que chaque philosophe doit manger pour que la simulation se termine.

- parametres
    - on peut recuper des arguments:
        - temps max de simulation
        - nombre de philosophes / fourchettes
        - chaque philosophe a un laps de temps pour dormir
            - 
- creer la table
    - recuperer le nombre de philosophes en parametres
    - allouer la memoire des tableau en fonction
    - remplir chaque element du tableau
        - faire une fonction de creation de fourchettes
        - faire une fonction de creation de philosophe

- creer une fourchette
    - recuperer id avec parametres
        - creer une fonction de recuperation d'id
    - assigner un etat inutilise

- creer un philosophe
    - lui donner un id
        - creer une fonction de recuperation d'id
    - creer une fonction pour recuperer l'id des fourchettes
    - initialiser le compte de repas a 0

### creation des threads

- creer le multithreading des pilosophes
	- ils doivent commencer par manger
		- verifier que les fourchettes sont disponibles
		- comment savoir combien de philosophes peuvent manger en meme temps?
	- ils passent ensuite en mode dodo
		- ici l'enjeux est le temps de sommeil minimum/maximum
	- ils passent ensuite en mode pensee

