#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n", t.name);
    int i, j;
    for(i=0;i<t.offices_count;i++) {
        printf("\t%d:\n", i);
        for(j=0;j<t.offices[i].packages_count;j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int i, j, k, l, m;
    package aux;
	aux.id = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    for(i=0;i<source->offices[source_office_index].packages_count;i++) {
        j = target->offices[target_office_index].packages_count;
        if(source->offices[source_office_index].packages[i].weight <= 
        target->offices[target_office_index].max_weight && source->offices
        [source_office_index].packages[i].weight >= 
        target->offices[target_office_index].min_weight) {
            target->offices[target_office_index].packages = (package*)realloc
            (target->offices[target_office_index].packages, (j+1)*sizeof(package));
			target->offices[target_office_index].packages[j].id = (char*)calloc
            (MAX_STRING_LENGTH, sizeof(char));
            for(l=0;source->offices[source_office_index].packages[i].id[l] != '\0';l++) {
				target->offices[target_office_index].packages[j].id[l] = 
				source->offices[source_office_index].packages[i].id[l];
			}
			target->offices[target_office_index].packages[j].weight = 
			source->offices[source_office_index].packages[i].weight;
			target->offices[target_office_index].packages_count++;
            for(k=i;k<source->offices[source_office_index].packages_count-1;k++) {
                for(m=0;source->offices[source_office_index].packages[k].id[m] != '\0';m++) {
					aux.id[m] = source->offices[source_office_index].packages[k].id[m];
					if(source->offices[source_office_index].packages[k+1].id[m] != '\0') {
						source->offices[source_office_index].packages[k].id[m] = 
						source->offices[source_office_index].packages[k+1].id[m];
					}
					source->offices[source_office_index].packages[k+1].id[m] = aux.id[m];
				}
				aux.weight = source->offices[source_office_index].packages[k].weight;
				source->offices[source_office_index].packages[k].weight = 
				source->offices[source_office_index].packages[k+1].weight;
				source->offices[source_office_index].packages[k+1].weight = aux.weight;
            }
            free(source->offices[source_office_index].packages[k].id);
            source->offices[source_office_index].packages = 
            (package*)realloc(source->offices[source_office_index].packages, 
            (source->offices[source_office_index].packages_count-1)*sizeof(package));
            source->offices[source_office_index].packages_count--;
			i--;
        }
    }
    	
}

town town_with_most_packages(town* towns, int towns_count) {
    int* max = (int*)calloc(towns_count, sizeof(int));
    for(int i=0;i<towns_count;i++) {
        for(int j=0;j<towns[i].offices_count;j++) {
            max[i] += towns[i].offices[j].packages_count;
        }
    }
    int t, m = 0;
    for(int k=0;k<towns_count;k++) {
        if(max[k] > m) {
            t = k;
			m = max[k];
		}
    }
    return towns[t];
}

town* find_town(town* towns, int towns_count, char* name) {
    for(int i=0;i<towns_count;i++) {
		int j = 0;
		while(towns[i].name[j] != '\0' && name[j] != '\0') {
			if(towns[i].name[j] != name[j])
				break;
			else if(towns[i].name[j] == name[j] && towns[i].name[j+1] == '\0' && name[j+1] == '\0') {
				return &towns[i];
			}
			j++;
		}
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}