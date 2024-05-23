#!/bin/bash
#SBATCH --job-name=sum
#SBATCH --output=result_%j.txt        # Output file name, where %j is the job ID
#SBATCH --partition=espec             # Explicitly specify the partition if needed
#SBATCH --nodes=4                     # Total number of nodes requested
#SBATCH --ntasks-per-node=1           # Number of tasks per node
#SBATCH --cpus-per-task=1             # Number of CPUs per task
#SBATCH --mem-per-cpu=100M            # Memory per CPU core

# Calculate total number of MPI processes to start
total_procs=$((SLURM_NTASKS_PER_NODE * SLURM_NNODES))

# Run the program using mpirun or mpiexec; adjust depending on your MPI implementation
mpirun -np $total_procs ./sum