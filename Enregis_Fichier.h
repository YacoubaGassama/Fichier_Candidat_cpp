#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
    string id,nom,prenom,ville,classe,exam,centre;
    float moyenne;
    string sexe;
}candidat;
void creationFC(){
    candidat ca;
    string reponse;
    ofstream fichCandidat("Candidat.txt");
    do{
        cout<<"Voulez vous ajouter un candidat O/N ? : ";
        cin>>reponse;
        if(reponse == "O"){
            cout<<"ID du candidat : ";
            cin>>ca.id;
            cout<<"Nom : ";
            cin>>ca.nom;
            cout<<"Prenom : ";
            cin>>ca.prenom;
            cout<<"Ville : ";
            cin>>ca.ville;
            cout<<"Classe : ";
            cin>>ca.classe;
            cout<<"Examen : ";
            cin>>ca.exam;
            cout<<"Centre : ";
            cin>>ca.centre;
            cout<<"Sexe : ";
            cin>>ca.sexe;
            do{
                cout<<"Moyenne : ";
                cin>>ca.moyenne;
            }while(ca.moyenne<0 || ca.moyenne>20);
            fichCandidat<<ca.id<<" "<<ca.nom<<" "<<ca.prenom<<" "<<ca.sexe<<" "<<ca.centre<<" "<<ca.classe<<" "<<ca.moyenne<<" "<<ca.ville<<" ";
        }
    }while(reponse == "O");
}
void afficheFichierCandidat(){
    candidat ca;
    ifstream fichCandidat("Candidat.txt");
    fichCandidat>>ca.id>>ca.nom>>ca.prenom>>ca.sexe>>ca.centre>>ca.exam>>ca.moyenne>>ca.ville;
    while(!fichCandidat.eof()){
        cout<<ca.id<<" "<<ca.nom<<" "<<ca.prenom<<" "<<ca.sexe<<" "<<ca.centre<<" "<<ca.classe<<" "<<ca.exam<<" "<<ca.moyenne<<" "<<ca.ville<<endl;;
        fichCandidat>>ca.id>>ca.nom>>ca.prenom>>ca.sexe>>ca.centre>>ca.exam>>ca.moyenne>>ca.ville;
    }
    fichCandidat.close();
}
void ajouterCandidat(){
        candidat ca;
    string reponse;
    ofstream fichCandidat("Candidat.txt",ios::app);
    do{
        cout<<"Voulez vous ajouter un candidat O/N ? : ";
        cin>>reponse;
        if(reponse == "O"){
            cout<<"ID du candidat : ";
            cin>>ca.id;
            cout<<"Nom : ";
            cin>>ca.nom;
            cout<<"Prenom : ";
            cin>>ca.prenom;
            cout<<"Ville : ";
            cin>>ca.ville;
            cout<<"Classe : ";
            cin>>ca.classe;
            cout<<"Examen : ";
            cin>>ca.exam;
            cout<<"Centre : ";
            cin>>ca.centre;
            cout<<"Sexe : ";
            cin>>ca.sexe;
            do{
                cout<<"Moyenne : ";
                cin>>ca.moyenne;
            }while(ca.moyenne<0 || ca.moyenne>20);
            fichCandidat<<ca.id<<" "<<ca.nom<<" "<<ca.prenom<<" "<<ca.sexe<<" "<<ca.centre<<" "<<ca.exam<<" "<<ca.classe<<" "<<ca.moyenne<<" "<<ca.ville<<" ";
        }
    }while(reponse == "O");
}
void statisque(){
    candidat ca;
    int nt=0,nbac=0,nbts=0,nbfem=0,nlicence=0,nmaster=0;
    float pbac,pbfem,plicence,pmaster,pbts;
    ifstream fichCandidat("Candidat.txt");
    fichCandidat>>ca.id>>ca.nom>>ca.prenom>>ca.sexe>>ca.centre>>ca.exam>>ca.moyenne>>ca.ville;
    while(!fichCandidat.eof()){
        nt++;
        if(ca.exam == "BAC"){
            nbac++;
        }
        if(ca.exam == "LICENCE"){
            nlicence++;
        }
        if(ca.exam == "BFEM"){
            nbfem++;
        }
        if(ca.exam == "MASTER"){
            nmaster++;
        }
        if(ca.exam == "BTS"){
            nbts++;
        }
        fichCandidat>>ca.id>>ca.nom>>ca.prenom>>ca.sexe>>ca.centre>>ca.exam>>ca.moyenne>>ca.ville;
    }
    fichCandidat.close();
    if(nt!=0){
        pbac = (float)nbac * 100 / nt ;
        pbfem = (float)nbfem * 100 / nt ;
        pmaster = (float)nmaster * 100 / nt ;
        plicence = (float)nlicence * 100 / nt ;
        pbts = (float)nbts * 100 / nt ;
        cout<<"Le pourcentage au BAC est : "<<pbac<<"%"<<endl;
        cout<<"Le pourcentage au Licence est : "<<plicence<<"%"<<endl;
        cout<<"Le pourcentage au Master est : "<<pmaster <<"%"<<endl;
        cout<<"Le pourcentage au BTS est : "<<pbts<<"%"<<endl;
        cout<<"Le pourcentage au BFEM est : "<<pbfem<<"%"<<endl;
    }
}
void menu(){
    int choix;
    do{
        cout<<"\n1-Creation\n2-Affichage\n3-Ajout\n4-Statistique\n0-Quitter\n\t";
        cin>>choix;
        switch(choix){
        case 1:
            creationFC();
            break;
        case 2:
            afficheFichierCandidat();
            break;
        case 3:
            ajouterCandidat();
            break;
        case 4:
            statisque();
            break;
        default:cout<<"CHOIX INDISPONIBLE";
            break;
        }
    }while(choix != 0);
}
