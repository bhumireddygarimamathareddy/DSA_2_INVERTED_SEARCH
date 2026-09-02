#include "inverted.h"
int main(int argc, char *argv[])
{
    F_node *head = NULL;
    hash HT[27];
     initialize_hash(HT);
    // Validate_files
if (argc > 1)
{
    if (validate_files(argc, argv, &head) == FAILURE)
    {
        printf("Error in validating the arguments\n");
        return FAILURE;
    }
    printf("The files are inserted into the linkedlist are:\n");
    printf("--------------------------------\n");
    print_file_list(head);
    printf("--------------------------------\n");
    printf("The files are validated successfully\n");
}
    int option;
    do
    {
	printf("Select your choice among following operations:\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n\nEnter your choice : ");

	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		create_database(HT, head);
		break;

	    case 2:
		display_database(HT);
		break;

	    case 3:
		save_database(HT);
		    break;

	    case 4:
		search_database(HT);
		break;

	    case 5:
		update_database(HT, &head);
		break;

	    case 6:
		break;

	    default:
		printf("INFO : Please enter the valid option\n");
	}
    }
	while( option != 6 );{
		printf("You are exiting from the inverting search operation\n");
		return 0;
	}
    return 0;
}
