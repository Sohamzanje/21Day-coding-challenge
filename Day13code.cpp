#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

struct Order {
    std::string orderId;
    std::string customerId;
    std::vector<std::string> productCodes;
};

void storeOrders(std::vector<Order>& orders) {
    orders.push_back({"order1", "customer1", {"productA", "productB", "productC"}});
    orders.push_back({"order2", "customer2", {"productA", "productC", "productC"}});
    orders.push_back({"order3", "customer1", {"productB", "productD"}});
    orders.push_back({"order4", "customer3", {"productA", "productB"}});
}

std::set<std::string> identifyUniqueProducts(const std::vector<Order>& orders) {
    std::set<std::string> uniqueProducts;
    
    for (const auto& order : orders) {
        for (const auto& productCode : order.productCodes) {
            uniqueProducts.insert(productCode);
        }
    }

    return uniqueProducts;
}

std::unordered_map<std::string, int> computeProductSalesCount(const std::vector<Order>& orders) {
    std::unordered_map<std::string, int> productSales;

    for (const auto& order : orders) {
        for (const auto& productCode : order.productCodes) {
            productSales[productCode]++;
        }
    }

    return productSales;
}

std::string findTopCustomer(const std::vector<Order>& orders) {
    std::unordered_map<std::string, std::set<std::string>> customerProducts;

    for (const auto& order : orders) {
        for (const auto& productCode : order.productCodes) {
            customerProducts[order.customerId].insert(productCode);
        }
    }

    std::string topCustomer;
    size_t maxDistinctProducts = 0;

    for (const auto& customer : customerProducts) {
        if (customer.second.size() > maxDistinctProducts) {
            maxDistinctProducts = customer.second.size();
            topCustomer = customer.first;
        }
    }

    return topCustomer;
}

int main() {
    std::vector<Order> orders;
    storeOrders(orders);

    std::set<std::string> uniqueProducts = identifyUniqueProducts(orders);
    std::cout << "Unique Products: ";
    for (const auto& product : uniqueProducts) {
        std::cout << product << " ";
    }
    std::cout << "\n";

    std::unordered_map<std::string, int> productSales = computeProductSalesCount(orders);
    std::cout << "Product Sales Count:\n";
    for (const auto& entry : productSales) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }

    std::string topCustomer = findTopCustomer(orders);
    std::cout << "Top Customer: " << topCustomer << "\n";

    return 0;
}
