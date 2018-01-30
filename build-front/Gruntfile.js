module.exports = function(grunt) {

    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),

        svgstore: {
            icons: {
                options: {
                    prefix : 'icon-',
                },
                files: {
                    '../themes/bookbox_ui/images/svg-icons-sprite.svg': ['../themes/bookbox_ui/icons-svg/*.svg']
                },
            },
            logos: {
                files: {
                    '../themes/bookbox_ui/images/svg-images-sprite.svg': 'img-svg/*.svg'
                }
            }
        },
    
        less: {
            development: {
                options: {
                    compress: true,
                    sourceMap: true,
                    cleancss: true
                },
                files: {
                    '../themes/bookbox_ui/css/style.css': 'less/style.less'
                }
            }
        },

        bake: {
            your_target: {
                options: {
                    // Task-specific options go here.
                },

                files: {
                    // files go here, like so:
                    "../themes/bookbox_ui/templates/page.tpl.php": "_templates-src/page.tpl.php",
                    "../themes/bookbox_ui/templates/page--user.tpl.php": "_templates-src/page--user.tpl.php",
                    "../themes/bookbox_ui/templates/page--type-book.tpl.php": "_templates-src/page--type-book.tpl.php",
                    "../themes/bookbox_ui/templates/page--user--login.tpl.php": "_templates-src/page--user--login.tpl.php",
                    "../themes/bookbox_ui/templates/page--user--register.tpl.php": "_templates-src/page--user--register.tpl.php",
                    "../themes/bookbox_ui/templates/page--user--password.tpl.php": "_templates-src/page--user--password.tpl.php",
                    "../themes/bookbox_ui/templates/page--user--reset.tpl.php": "_templates-src/page--user--reset.tpl.php",
                    "../themes/bookbox_ui/templates/page--taxonomy_vocabulary__publishers.tpl.php": "_templates-src/page--taxonomy_vocabulary__publishers.tpl.php",
                    "../themes/bookbox_ui/templates/page--taxonomy_vocabulary__authors.tpl.php": "_templates-src/page--taxonomy_vocabulary__authors.tpl.php",
                    "../themes/bookbox_ui/templates/page--taxonomy_vocabulary__collections.tpl.php": "_templates-src/page--taxonomy_vocabulary__collections.tpl.php"
                }
            }
        },

        watch: {
            grunt: {
                files: ['Gruntfile.js']
            },

            svgstore: {
                files: [
                    '../themes/bookbox_ui/icons-svg/*.svg',
                    '../themes/bookbox_ui/img-svg/*.svg'
                ],
                tasks: ['svgstore']
            },

            less: {
                files: [
                    'less/**/*.less',
                    'less/**/**/*.less'
                ],
                tasks: ['less', 'postcss']
            },

            bake: {
                files: [
                    '_templates-src/**/*.php'
                ],
                tasks: ['bake']
            }

        },
        
        postcss: {
            options: {
              map: true,
              processors: [
                require('autoprefixer')({browsers: ['last 2 versions', 'ie 10']})
              ]
            },
            dist: {
              src: '../themes/bookbox_ui/css/style.css'
            }
        }
    });

    // load npm modules
    grunt.loadNpmTasks('grunt-bake');
    grunt.loadNpmTasks('grunt-svgstore');
    grunt.loadNpmTasks('grunt-contrib-clean');
    grunt.loadNpmTasks('grunt-contrib-less');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-postcss');

    grunt.registerTask('default', ['bake', 'svgstore',  'less', 'postcss', 'watch']);
    grunt.registerTask('jenkins', ['bake',  'svgstore',   'less', 'postcss']);
};
