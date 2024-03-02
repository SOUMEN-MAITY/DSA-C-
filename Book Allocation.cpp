#include <bits/stdc++.h> 
bool isPossible(vector<int> &pages, int n, int b,int mid){
	int studentCount=1;
	int totalpages=0;
	for(int i=0;i<n;i++){
		if(totalpages+pages[i]<=mid){
			totalpages+=pages[i];
		}
		else{
			studentCount++;
			if(studentCount>b || pages[i]>mid){
				return false;
			}
			totalpages=pages[i];
			

		}
		if(studentCount>b){
				return false;
			}
	}
	return true;
}


int allocateBooks(vector<int> &pages, int n, int b)
{
	// Write your code here.
	int s=0;
	int ans=-1;
	int sum=0;
	for(int i=0;i<n;i++){
		sum +=pages[i];
	}
	int e=sum;
	int mid = s+(e-s)/2;
	if(b>n){
		return -1;
	}
	while(s<=e){

		if(isPossible(pages, n, b,mid)){
			ans=mid;
			e=mid-1;
			
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}
