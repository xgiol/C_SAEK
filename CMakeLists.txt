# =============================================================================
# Γλώσσα Προγραμματισμού Ι (C11) - Αλγοριθμική και Δομές Δεδομένων
# Ριζικό CMakeLists.txt
#
# Αυτό το αρχείο χτίζει ΟΛΑ τα προγράμματα του μαθήματος (ένα εκτελέσιμο ανά
# αρχείο .c) μέσα από τους φακέλους src/weekNN/ , με ομοιόμορφο τρόπο σε
# Windows, macOS και Linux, ανεξάρτητα από τον compiler που είναι
# εγκατεστημένος (MSVC, gcc, clang).
#
# Χρήση (ίδια εντολή σε όλα τα λειτουργικά συστήματα):
#
#   cmake -S . -B build
#   cmake --build build
#
# Τα εκτελέσιμα δημιουργούνται μέσα στο build/bin/weekNN/
# Δείτε το README.md και το docs/BUILD.md για αναλυτικές οδηγίες ανά OS.
# =============================================================================

cmake_minimum_required(VERSION 3.16)

project(C_SAEK LANGUAGES C)

# Πρότυπο γλώσσας: C11 (όπως ορίζει ο τίτλος του μαθήματος)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Όλα τα εκτελέσιμα καταλήγουν σε ένα κοινό, οργανωμένο σημείο
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ενεργοποίηση χρήσιμων προειδοποιήσεων -- βοηθούν πολύ τους αρχάριους να
# εντοπίζουν λάθη νωρίς, χωρίς να είναι υπερβολικά αυστηρές (δεν είναι -Werror).
if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra)
endif()

# Η βιβλιοθήκη math.h στη Linux/macOS θέλει σύνδεση με τη libm (-lm).
# Στα Windows/MSVC δεν χρειάζεται. Το παρακάτω βοηθητικό βρίσκει τη σωστή τιμή.
if (UNIX)
    find_library(MATH_LIBRARY m)
endif()

# ---------------------------------------------------------------------------
# Βοηθητική συνάρτηση: προσθέτει ΚΑΘΕ αρχείο .c ενός φακέλου εβδομάδας ως
# ξεχωριστό εκτελέσιμο πρόγραμμα, μέσα στο δικό του υποφάκελο στο build/bin.
# ---------------------------------------------------------------------------
function(add_week_programs week_dir)
    file(GLOB week_sources CONFIGURE_DEPENDS "${week_dir}/*.c")
    file(GLOB week_exercise_sources CONFIGURE_DEPENDS "${week_dir}/exercises/*.c")
    list(APPEND week_sources ${week_exercise_sources})

    get_filename_component(week_name "${week_dir}" NAME)

    foreach(src_file ${week_sources})
        get_filename_component(exe_name "${src_file}" NAME_WE)
        # Μοναδικό όνομα target: π.χ. week05_04_for_demo
        set(target_name "${week_name}_${exe_name}")

        add_executable(${target_name} "${src_file}")
        set_target_properties(${target_name} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${week_name}"
        )
        if (UNIX AND MATH_LIBRARY)
            target_link_libraries(${target_name} PRIVATE ${MATH_LIBRARY})
        endif()
    endforeach()
endfunction()

# Βρες αυτόματα όλους τους φακέλους weekNN μέσα στο src/ και πρόσθεσέ τους
file(GLOB week_dirs LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/week*")
foreach(week_dir ${week_dirs})
    if (IS_DIRECTORY ${week_dir})
        add_week_programs(${week_dir})
    endif()
endforeach()

# ---------------------------------------------------------------------------
# Μικρό μήνυμα βοήθειας μετά το configure
# ---------------------------------------------------------------------------
message(STATUS "")
message(STATUS "=========================================================")
message(STATUS " Γλώσσα Προγραμματισμού Ι (C11) -- ρυθμίστηκε επιτυχώς!")
message(STATUS " Χτίσιμο όλων των προγραμμάτων: cmake --build build")
message(STATUS " Τα εκτελέσιμα θα βρίσκονται στο: build/bin/weekNN/")
message(STATUS "=========================================================")
message(STATUS "")
