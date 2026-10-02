#ifndef ASSET_H
#define ASSET_H

/* ================= ASSET MANAGEMENT ================= */

/* Displays the Asset Management menu */
void assetMenu(void);


/* ================= ASSET GETTERS ================= */

/* Returns the number of registered assets */
int getAssetCount(void);

/* Returns the ID of an asset */
int getAssetID(int i);

/* Returns the name of an asset */
const char *getAssetName(int i);

/* Returns the type of an asset */
const char *getAssetType(int i);

/* Returns the value of an asset */
float getAssetValue(int i);

/* Returns the department responsible for an asset */
const char *getAssetDepartment(int i);

/* Returns the condition of an asset */
const char *getAssetCondition(int i);

/* Returns the total value of all registered assets */
float getTotalAssetValue(void);

#endif /* ASSET_H */
