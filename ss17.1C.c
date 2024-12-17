#include<stdio.h>
void addItem(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("Moi ban nhap vao phan tu thu index %d: ",i);
		scanf("%d",&arr[i]);
	}
	printf("\n");
}
void showItem(int *arr, int size){
	for(int i=0;i<size;i++){
		printf("arr[%d]: %d\t",i,arr[i]);
	}
	printf("\n");
}
void length(int *arr,int size){
	printf("%d",size);
	printf("\n");
}
void sumItem(int *arr,int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=arr[i];
	}
	printf("%d",sum);
	printf("\n");
}
void maxItem(int *arr,int size){
	int max=arr[0];
	for(int i=0;i<size;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	printf("%d",max);
	printf("\n");
}
int main(){
	int menu;
	int count=0;
	int arr[100];
	int size;
	
	do{
		printf("MENU\n");
		printf("1. Nhap vao so phan tu va tung phan tu\n");
		printf("2. Hien thi cac phan tu trong mang\n");
		printf("3. Tinh do dai mang\n");
		printf("4. Tinh tong cac phan tu trong mang\n");
		printf("5. Hien thi phan tu lon nhat\n");
		printf("6. Thoat\n");
		scanf("%d",&menu);
		
		if(count==0&&menu!=1&menu!=6){
			printf("Mang rong, moi ban chon 1 de nhap vao cac phan tu\n");
			continue;
		}
		
		switch(menu){
			case 1:
				printf("Moi ban nhap vao so phan tu: ");
				scanf("%d",&size);
				addItem(arr,size);
				count++;
				break;
			case 2:
				printf("Cac phan tu trong mang la: \n");
				showItem(arr,size);
				break;
			case 3:
				printf("Do dai cua mang la: ");
				length(arr,size);
				break;
			case 4:
				printf("Tong cac phan tu trong mang la: ");
				sumItem(arr,size);
				break;
			case 5:
				printf("Phan tu lon nhat trong mang la: ");
				maxItem(arr,size);
				break;
			case 6: 
			printf("Thoat");
				break;
			default:
				printf("Khong hop le!!!\n");
		}
	}
	while(menu!=6);
	
	return 0;
}
