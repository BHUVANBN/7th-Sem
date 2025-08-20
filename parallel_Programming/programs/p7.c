// Program 7: Write an MPI program to demonstrate broadcast operation (MPI_Bcast).
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int rank, data = 0;
    MPI_Init(&argc, &argv);   // Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get the rank of the process

    if (rank == 0) data = 100;  // Root sets the data

    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD); // Broadcast data from root process (rank 0) to all other processes
    printf("Process %d received data: %d\n", rank, data); // Each process prints the received data

    MPI_Finalize(); // Finalize the MPI environment
    return 0;
}
/*                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpicc p7.c -o p7 
                                                                                     
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpirun -np 4 ./p7

[batman][[11955,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[11955,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
Process 0 received data: 100
Process 2 received data: 100
Process 1 received data: 100
Process 3 received data: 100

*/