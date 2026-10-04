#ifndef ASSETS_H
#define ASSETS_H
 

void assetMenu(void);
 

int   getAssetCount(void);
int   getAssetID(int index);
float getAssetValue(int index);
void  getAssetName(int index, char name[]);
void  getAssetType(int index, char type[]);
void  getAssetDepartment(int index, char department[]);
void  getAssetCondition(int index, char condition[]);
float getTotalAssetValue(void);
 
#endif

