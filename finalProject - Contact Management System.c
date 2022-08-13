#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contact
{
    char Name[25], email[45], company[35], address[50], designation[25];
    long int *Contact, work, fax, emergency;
    int zip;
};
int main()
{
    struct contact *c;
    int choice,choice1, i=0, j = 1, k, l, m, a=0, same = 1,same1=1, found = 1,found1=1,cnt=1,total=0,c1,c2,c3,w,f,e,z;
    char another, search[25],n[25],em[45],co[35],add[50],d[25],search1[25],n1[25];
    FILE *fpo,*fpd,*fp1,*fp2;
    c=(struct contact*)malloc(sizeof(struct contact));
    c->Contact=(long int*)malloc(sizeof(long int));
    
    main:
    printf("Enter your choice:\n1.Contact Entry\n2.Contact Editing\n3.Display Contacts\n4.Contact Deleting\n5.Exit\n");
    fflush(stdin);
    scanf("%d", &choice);
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
        	start:
        	j=1;
        	fpd=fopen("C:\\Contacts.txt","r");
            fpo=fopen("C:\\Contacts.txt","a");
            if (fpo==NULL)
            {
                printf("File not open/found");
                exit(0);
            }
            else
            {
                for(i=0;i<j;i++)
                {	
					found=1;
                	while(found==1){
                    	printf("Enter Contact Name:");
                    	fflush(stdin);
                    	gets((c+i)->Name);
                    	found=0;
                    	while((fscanf(fpd,"%s %ld %ld %ld %s %s %ld %ld %d %s %s %ld",n,&c1,&c2,&c3,em,co,&w,&f,&z,add,d,&e)!=EOF))
						{
							if((stricmp((c+i)->Name,n))!=0)
							{
								continue;
							}
							else if((stricmp((c+i)->Name,n))==0)
							{
								found=1;
								printf("This name is already taken! Enter another name.\n");
								fclose(fpd);
								goto start;
								break;
							}
						}
					}
                    for (k = 0; k < f; k++)
                    {
                        printf("Enter Contact Number: ");
                        fflush(stdin);
                        scanf("%ld", &(c+i)->Contact[k]);
                        
                        
                            printf("Add another number to the same contact?(y/n)");
                            fflush(stdin);
                            scanf(" %c", &another);
                            
                            if (another == 'Y' || another == 'y')
                            {
                            f++;
                            c->Contact=(long int*)realloc(c->Contact,(f + 1)* sizeof(long int));
                            }
                            else
                            {
                            	break;
							}
                        
                    }
                    printf("Enter Email address:");
                    fflush(stdin);
                    gets((c+i)->email);
                    printf("Enter Company Name:");
                    fflush(stdin);
                    gets((c+i)->company);
                    printf("Enter work number: ");
                    fflush(stdin);
                    scanf("%ld", &(c+i)->work);
                    printf("Enter fax number: ");
                    fflush(stdin);
                    scanf("%ld", &(c+i)->fax);
                    printf("Enter zip code: ");
                    fflush(stdin);
                    scanf("%d", &(c+i)->zip);
                    printf("Enter address:");
                    fflush(stdin);
                    gets((c+i)->address);
                    printf("Enter contact's designation:");
                    fflush(stdin);
                    gets((c+i)->designation);
                    printf("Enter emergency number: ");
                    fflush(stdin);
                    scanf("%ld", &(c+i)->emergency);
                    printf("Add another number to the same contact?(y/n)");
                            fflush(stdin);
                            scanf(" %c", &another);
                            
                            if (another == 'Y' || another == 'y')
                            {
                            
						 ++j;
                    c=(struct contact*)realloc(c,(j + 1)* sizeof(struct contact));
                    system("cls");
                            }
                            else
                            {
                            	system("cls");
                            
							}
    fprintf(fpo,"%s %ld  %s %s %ld %ld %d %s %s %ld",c->Name,c->Contact,c->email,c->company,c->work,c->fax,c->zip,c->address,c->designation,c->emergency);
                    
                }
                fclose(fpd);
                fclose(fpo);
            }
            break;
        case 2:
        	fp1=fopen("C:\\New.txt","w");
        	fp2=fopen("C:\\Contacts.txt","r");
            printf("Enter the name of the contact you want to edit: ");
            fflush(stdin);
            gets(search);
			while((fscanf(fp2,"%s %ld %ld %ld %s %s %ld %ld %d %s %s %ld",n,&c->Contact,em,co,&w,&f,&z,add,d,&e)!=EOF))
			{
				if((strcmp(search,n))!=0)
				{
					fprintf(fp1,"%s %ld %s %s %ld %ld %d %s %s %ld",n,c->Contact,em,co,w,f,z,add,d,e);
				}
				else if((strcmp(search,n))==0)
				{
					fflush(stdin);
					printf("Editing contact record for %s\n",search);
					edit:
					printf("Enter new Contact Name:");
                    gets(n1);
                    found1=1;
                	while(found1==1){
                		fpd=fopen("C:\\Contacts.txt","r");
                    	found1=0;
                    	while((fscanf(fpd,"%s %ld %s %s %ld %ld %d %s %s %ld",n,&c->Contact,em,co,&w,&f,&z,add,d,&e)!=EOF))
						{
							if((stricmp(n1,n))!=0)
							{
								continue;
							}
							else if((stricmp(n1,n))==0)
							{
								found1=1;
								printf("This name is already taken! Enter another name.\n");
								fclose(fpd);
								goto edit;
								break;
							}
						}
					}
					fclose(fpd);
                     for (k = 0; k < f; k++)
                    {
                        printf("Enter Contact Number: ");
                        scanf("%ld", &c->Contact[k]);
                        
                        
                             if (another == 'Y' || another == 'y')
                            {
                            f++;
                            c->Contact=(long int*)realloc(c->Contact,(f + 1)* sizeof(long int));
                            }
                            else
                            {
                            	break;
							}
                        
                    }
                    
                    printf("Enter new Email address:");
                    fflush(stdin);
                    gets(em);
                    printf("Enter new Company Name:");
                    fflush(stdin);
                    gets(co);
                    printf("Enter new work number: ");
                    fflush(stdin);
                    scanf("%ld", &w);
                    printf("Enter new fax number: ");
                    fflush(stdin);
                    scanf("%ld", &f);
                    printf("Enter new zip code: ");
                    fflush(stdin);
                    scanf("%d", &z);
                    printf("Enter new address:");
                    fflush(stdin);
                    gets(add);
                    printf("Enter new contact's designation:");
                    fflush(stdin);
                    gets(d);
                    printf("Enter new emergency number: ");
                    fflush(stdin);
                    scanf("%ld", &e);
					fprintf(fp1,"%s %ld %s %s %ld %ld %d %s %s %ld",n1,c->Contact,em,co,w,f,z,add,d,e);
				}
			}
			fclose(fp2);
			fclose(fp1);
			remove("C:\\Contacts.txt");
			rename("C:\\New.txt","D:\\Contacts.txt");
            break;
        case 3:
        	fpd=fopen("C:\\Contacts.txt","r");
        	if (fpd==NULL)
            {
                printf("File not open/found");
                exit(0);
            }
			while((fscanf(fpd,"%s %ld %s %s %ld %ld %d %s %s %ld",n,&c->Contact,em,co,&w,&f,&z,add,d,&e)!=EOF)){
			
			printf("Name: %s\nContact1: %ld\nContact2: %ld\nContact3: %ld\nAddress: %s\nCompany Name: %s\nDesignation: %s\nWork Number: %ld\nEmail address: %s\nFax Number: %ld\nEmergency contact: %ld\nZIP: %d\n\n",n,c->Contact,add,co,d,w,em,f,e,z);
			}
            fclose(fpd);
            break;
		case 4:
			fp1=fopen("C:\\Delete.txt","w");
        	fp2=fopen("C:\\Contacts.txt","r");
            printf("Enter the name of the contact you want to delete: ");
            fflush(stdin);
            gets(search1);
			while((fscanf(fp2,"%s %ld %ld %ld %s %s %ld %ld %d %s %s %ld",n,&c->Contact,em,co,&w,&f,&z,add,d,&e)!=EOF))
			{
				if(strcmp(search1,n)==0)
				{
					continue;
				}
				else if(strcmp(search1,n)!=0)
				{
					fprintf(fp1,"%s %ld %ld %ld %s %s %ld %ld %d %s %s %ld",n,c->Contact,em,co,w,f,z,add,d,e);
				}       
			} 
			fclose(fp2);
			fclose(fp1);
			remove("C:\\Contacts.txt");
			rename("C:\\Delete.txt","C:\\Contacts.txt");
			break;
        default:
            break;
        }
        goto main;
    }
}
