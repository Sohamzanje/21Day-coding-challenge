#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Employee {
public:
    int employee_id;
    string name;
    unordered_set<string> skills;

    Employee(int id, string name, unordered_set<string> skills)
        : employee_id(id), name(name), skills(skills) {}
};

class Project {
public:
    int project_id;
    string name;
    unordered_set<string> required_skills;
    string deadline;

    Project(int id, string name, unordered_set<string> required_skills, string deadline)
        : project_id(id), name(name), required_skills(required_skills), deadline(deadline) {}
};

// Function to find if an employee qualifies for a project
bool qualifiesForProject(const Employee& employee, const Project& project) {
    // Employee qualifies if their skills are a superset of the required skills for the project
    for (const string& skill : project.required_skills) {
        if (employee.skills.find(skill) == employee.skills.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // Step 1: Create employees and projects
    vector<Employee> employees = {
        Employee(1, "Ram", {"Java", "SQL", "Python"}),
        Employee(2, "Ravi", {"Java", "Python"}),
        Employee(3, "Shravani", {"Java", "SQL"}),
        Employee(4, "Gauri", {"SQL", "Python"}),
        Employee(5, "Ramesh", {"Java", "SQL", "Python"})
    };

    vector<Project> projects = {
        Project(101, "Project A", {"Java", "Python"}, "2025-06-01"),
        Project(102, "Project B", {"SQL"}, "2025-07-01"),
        Project(103, "Project C", {"Java", "SQL"}, "2025-08-01")
    };

    // Step 2: Employee Skills Mapping (Map<EmployeeID, Set<Skill>>)
    unordered_map<int, unordered_set<string>> employee_skills;
    for (const Employee& emp : employees) {
        employee_skills[emp.employee_id] = emp.skills;
    }

    // Step 3: Project Assignment (Map<ProjectID, List<EmployeeID>>)
    unordered_map<int, vector<int>> project_assignments;

    for (const Project& project : projects) {
        vector<int> qualified_employees;
        for (const Employee& employee : employees) {
            if (qualifiesForProject(employee, project)) {
                qualified_employees.push_back(employee.employee_id);
            }
        }
        project_assignments[project.project_id] = qualified_employees;
    }

    // Step 4: Assignment Statistics (Map<EmployeeID, Integer>)
    unordered_map<int, int> employee_project_counts;
    for (const auto& entry : project_assignments) {
        for (int emp_id : entry.second) {
            employee_project_counts[emp_id]++;
        }
    }

    // Step 5: Identify Employee with Maximum Assignments
    int max_assignments = 0;
    int max_employee_id = -1;
    for (const auto& entry : employee_project_counts) {
        if (entry.second > max_assignments) {
            max_assignments = entry.second;
            max_employee_id = entry.first;
        }
    }

    cout << "Project Assignments:" << endl;
    for (const auto& entry : project_assignments) {
        cout << "Project " << entry.first << ": Assigned Employees: ";
        for (int emp_id : entry.second) {
            cout << emp_id << " ";
        }
        cout << endl;
    }

    cout << "\nAssignment Statistics:" << endl;
    for (const Employee& emp : employees) {
        int project_count = employee_project_counts[emp.employee_id];
        cout << "Employee " << emp.name << " (ID: " << emp.employee_id
             << ") is assigned to " << project_count << " projects." << endl;
    }

    cout << "\nEmployee with maximum project assignments: ";
    for (const Employee& emp : employees) {
        if (emp.employee_id == max_employee_id) {
            cout << emp.name << " (ID: " << max_employee_id << ")" << endl;
        }
    }

    return 0;
}
