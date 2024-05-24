#!/bin/bash
#SBATCH --job-name=victor
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=5
#SBATCH --cpus-per-task=1
#SBATCH --partition=espec
#SBATCH --mem=100M

export OMP_NUM_THREADS=5

# Calculate total number of MPI processes to start
total_procs=$((SLURM_NNODES))

echo Total processes created $total_procs

# Run the program using mpirun or mpiexec; adjust depending on your MPI implementation
mpirun -np $total_procs ./main
