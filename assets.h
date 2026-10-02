#ifndef ASSETS_H
#define ASSETS_H

void        assetMenu(void);
int         getAssetCount(void);
int         getAssetID(int index);
const char *getAssetName(int index);
const char *getAssetType(int index);
float       getAssetValue(int index);
const char *getAssetDepartment(int index);
const char *getAssetCondition(int index);
float       getTotalAssetValue(void);

#endif

