# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Group number:** 22

## Group Members
| Name | Student No. | Responsibility |
|---|---|---|
| Cala Dausas | 226167917 | Employee Management |
| Laudika Hakandume | 226043630 | Budget Management |
| Mbeurora Kangootui | 226096467 | Supplier Management |
| Victoria Peelenga | 226103099 | Asset Management |
| Litungeni Haimbodi | 226147924 | Reports |
| Arikleine Catate | 226022579 | Functions, integration & validation |
| Aaliyah Lunguti | 225045591 | Testing, documentation & Git coordination |

## Project Description
Our project is a menu driven C application that helps a municipality manage employees, budgets, suppliers, assets, and also produce reports.

## System Features
- Main menu that has very clear navigation
- Employees: add, display, search and salary calculation
- Budget: enter budgets and expenditure, remaining balance, detects when over budget
- Suppliers: add, display, search
- Assets: add, display, search
- Reports: employee, budget, supplier and asset reports
- Input validation for negative values, empty names and invalid menu choices

## Files
- `main.c` – main menu and program start
- `employee.c` / `employee.h` – employee management
- `budget.c` / `budget.h` – budget management
- `supplier.c` / `supplier.h` – supplier management
- `asset.c` / `assets.h` – asset management
- `report.c` – reports
- `utilities.c` / `utilities.h` – safe input helper

## Compilation
    gcc main.c employee.c budget.c supplier.c asset.c report.c utilities.c -o mfms

## How to Run
- Windows: `mfms.exe`
- Linux/Mac: `./mfms`

## Individual Responsibilities
- **Cala Dausas:** Employee Management (employee.c): employeeMenu, addEmployee, displayEmployees, searchEmployee, calculateSalary, getEmployeeCount, getAverageSalary, getHighestSalary, getLowestSalary

- **Laudika Hakandume:** Budget Management (budget.c): budgetMenu, addDepartmentBudget, enterExpenditure, displayBudgets, displayExceededDepartments, calculateRemaining, isWithinBudget, getTotalAllocated, getTotalExpenditure

- **Mbeurora Kangootui:** Supplier Management (supplier.c): supplierMenu, addSupplier, displaySuppliers, searchSupplierID, searchSupplierName

- **Victoria Peelenga:** Asset Management (asset.c): assetMenu, addAsset, displayAssets, searchAsset, getTotalAssetValue

- **Litungeni Haimbodi:** Reports (report.c): reportMenu, assetReport, budgetReport

- **Arikleine Catate:** Functions, integration and validation (main.c): main, clear

- **Aaliyah Lunguti:** Testing, documentation and Git coordination (README.md, technical report, test plan); utilities.c: readInt