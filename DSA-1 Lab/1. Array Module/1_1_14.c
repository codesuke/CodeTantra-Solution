#include <stdio.h>
int main(){
	int n,i,j,elements;
	scanf("%d",&n);
	int arr[n];
	for(i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c;
		scanf("%c",&c);
		if(c=='\n'){
			break;
		}
	}
	for(i=1;i<n;i++){
		int key=arr[i];
		j=i-1;
		while(key<arr[j]&& j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	if(n==elements){
		for(i=0;i<n;i++){
			if(i<n-1){
				printf("%d ",arr[i]);
			}
			else{
				printf("%d\n",arr[i]);
			}
		}
	}
	else{
		printf("-1");
	}
}