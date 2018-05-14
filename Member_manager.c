#include <conio.h>
#include <stdio.h>
#include <string.h>

struct member{
	int ID;
	char name[50];
	int age;
	int group_id;
};
typedef struct member member;
member MB[200];
int Num_Of_Mem = 0;

void Insert_member();

void Edit_member_info();

void showMenu();

void Del_member();

void Show_list_member();

void Arrange();

int main()

{
{
    MB[Num_Of_Mem].ID = 1;
    strcpy(MB[Num_Of_Mem].name, "nguyen a");
    MB[Num_Of_Mem].age = 12;
    MB[Num_Of_Mem++].group_id = 1;
    MB[Num_Of_Mem].ID = 2;
    strcpy(MB[Num_Of_Mem].name, "nguyen b");
    MB[Num_Of_Mem].age = 12;
    MB[Num_Of_Mem++].group_id = 1;
    MB[Num_Of_Mem].ID = 3;
    strcpy(MB[Num_Of_Mem].name, "nguyen c");
    MB[Num_Of_Mem].age = 12;
    MB[Num_Of_Mem++].group_id = 2;
}
    char ch;
	while(1){
		system("cls");
		showMenu();
		fflush(stdin);
		ch = getch();
		if(ch == '1') Insert_member();
		else if(ch == '2') Edit_member_info();
		else if(ch == '3') Show_list_member();
		else if(ch == '4') Del_member();
		else if(ch == '5') Arrange();
		else
		{
			fflush(stdin);
			printf("\n chan roi a ? Y/N");
			ch = getch();
			if(ch == 'Y' || ch == 'y') break;
		}
	}
	//xuatFile();
	return 0;
}


void showMenu(){
	printf("\n CHUONG TRINH QUAN LY THANH VIEN DOI\n ");
		printf("\n       =========MENU========= ");
		printf("\n 	1. Bo sung danh sach");
		printf("\n 	2. Sua chua thong tin");
		printf("\n 	3. In danh sach");
		printf("\n 	4. Xoa thanh vien");
		printf("\n 	5. Sap xep danh sach");
		printf("\n 	Bam 1-5 de chon, phim bat ki de ket thuc\n");
}

void Insert_member(){
	while(1){
        printf("nguoi thu %d :\n", Num_Of_Mem + 1);
        printf("Nhap ID: ");
        scanf("%d",&MB[Num_Of_Mem].ID);
        if(MB[Num_Of_Mem].ID == '\0' || MB[Num_Of_Mem].ID == '\n') break;
        printf("\nHo va ten: ");
        fflush(stdin);
        gets(MB[Num_Of_Mem].name);
        printf("\nTuoi:");
        scanf("%d", &MB[Num_Of_Mem].age);
        printf("\nGroup ID: ");
        scanf("%d", &MB[Num_Of_Mem].group_id);
        Num_Of_Mem++;
    }
}


void Edit_member_info(){
    printf("\nNhap ID cua thanh vien can sua:");
    int ID_edit;
    scanf("%d", &ID_edit);
    int flag=0;// bien kiem tra xem co tim thay hay khong
    for(int i = 0; i < Num_Of_Mem; i++){
        if(MB[i].ID == ID_edit) {
            flag = 1;
            char ch;
            printf("\nban muon sua thong tin: ");
            printf("\n1. Ho va ten");
            printf("\n2. Tuoi");
            printf("\n3. Nhom");
            ch = getch();
            while(ch != '1' || ch != '2' || ch != '3'){
                printf("\nmoi ban nhap lai!");
                ch = getch();
            }
            char Temp_name[50];
            int Temp_int;
            switch(ch){
                case '1':

                    fflush(stdin);
                    gets(Temp_name);
                    strcpy(MB[i].name, Temp_name);
                    break;
                case '2':

                    scanf("%d", &Temp_int);
                    MB[i].age = Temp_int;
                    break;
                default:
                    scanf("%d", &Temp_int);
                    MB[i].group_id = Temp_int;
                }

        }
    }
    if(flag == 0) printf("Khong tim thay thanh vien nay");
}

void Show_list_member(){

    if(Num_Of_Mem == 0) printf("\nChua co thanh vien nao!");
    else
    {   int stt = 1;
        printf("\n===DANH SACH THANH VIEN===\n");
        printf("\tSTT\t|\tID\t\t|\tHo ten\t\t\t|\tTuoi\t|\tGroup\n");
        for(int i = 0; i < Num_Of_Mem; i++){
            printf("\t%d\t|\t%d\t\t|\t%s\t\t\t|\t%d\t|\t%d\n", stt++, MB[i].ID, MB[i].name, MB[i].age, MB[i].group_id);
        }
        getch();
    }
}

void Del_member(){
    Show_list_member();
    printf("nhap ID cua thanh vien can xoa: ");
    int Temp_id;
    scanf("%d", Temp_id);
    for(int i = 0; i < Num_Of_Mem; i++){
        if(MB[i].ID == Temp_id){
            for(int j = i; j < Num_Of_Mem; j++){
                MB[j].ID = MB[j + 1].ID;
                printf("flag");
                strcpy(MB[j].name, MB[j + 1].name);
                printf("flag");
                MB[j].age = MB[j + 1].age;
                MB[j].group_id = MB[j + 1].group_id;
            }
            printf("flag");
            Num_Of_Mem--;
            break;
        }
    }
    printf("flag");
    getch();
}

void Arrange(){

}
