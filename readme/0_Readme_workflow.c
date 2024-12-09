
/**
 * Workflow: From Wallet Creation to Smart Contract Deployment:
 * 
 * 1.-  Create a Wallet Account (it is your gateway to the blockchain)
 *      A wallet account is a digital tool that allows you to store and interact with blockchain networks.
 *      This wallet will act as the sender of the transaction and provide the funds for deploying the smart contract.
 * 
 * 2.-  Generate Private and Public Keys
 *      A private key is a secret code used to sign transactions, and the corresponding public key is your blockchain address.
 *      The private key ensures secure control of your wallet account and is required to authorize the deployment of the smart contract.
 * 
 * 3.-  Write the Smart Contract (it  is the logic that governs the application)
 *      A smart contract is a piece of code written in a blockchain-compatible language.
 *      This contract defines the logic and rules for the application. It’s just code until deployed to the blockchain.
 * 
 * 4.-  Compile the Smart Contract
 *      The source code is converted into bytecode that the blockchain can execute.
 *      Compilation produces an ABI (Application Binary Interface) and bytecode, both of which are essential for deployment and interaction.
 * 
 * 5.-  Deploy the Smart Contract (it is the process of making the contract live on the blockchain)
 *      The compiled contract is sent to the blockchain as a transaction, creating a unique address where the contract resides.
 *      Use the wallet account (with sufficient funds to cover gas fees (*)).
 *      Sign the deployment transaction with the private key.
 *      Broadcast the transaction to the blockchain network.
 *      Once deployed, the smart contract becomes active and ready to be interacted with.
 *      Once live, the Contract Address allows others to interact securely with the contract.
 * 
 * 6.-  Get the Smart Contract Address
 *      After deployment, the blockchain assigns a unique address to the contract.
 *      This address is used to interact with the contract using the ABI.
 * 
 * 7.-  Interact with the Smart Contract
 *      Use the wallet account and the contract’s ABI to call functions, send transactions, or retrieve data.
 *      Signing transactions with the private key ensures secure communication between the user and the smart contract.
 * 
 * 
 * 
 * (*) gas fees -> A small amount of cryptocurrency paid to blockchain validators for processing and verifying transactions, 
 *                 including deploying or interacting with smart contracts. It ensures the network remains secure and operational.
 *                 The fee amount depends on network activity and the complexity of the transaction.
 *                 One of the primary goals when working with blockchain transactions—such as deploying or interacting with smart contracts—
 *                 is to achieve effective transactions with low gas fees.
 *                 When designing your workflow for deploying and managing smart contracts, consider gas fees at each stage:
 *                 1.- Development Phase
 *                     Write optimized code
 *                     Use testing tools to estimate gas usage
 *                 2.- Deployment Phase
 *                     Choose a network with favorable gas fees.
 *                     Deploy during times of lower network congestion.
 *                 3.- Interaction Phase
 *                     Optimize how users interact with the contract to minimize transactions.
 *                     Implement Layer 2 solutions if necessary.
 *                 4.- Maintenance Phase
 *                     Continuously monitor gas prices and adjust strategies.
 *                     Update contracts to incorporate new gas-saving techniques.
 */
